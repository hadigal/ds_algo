/******************************** LC:102 ***********************************
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// implemented a O(n) times solution
// used queue to store the nodes at each levelOrder. counted the nodes while enqueue
// and stored the same in a variable which will be used to iterate during dequeue operation and
// store value of nodes in an 2d array where each row represents the level and col
// represents the node key at each level.

void enqueue(struct TreeNode **queue, int *curr, struct TreeNode *val)
{
    *curr += 1;
    queue[*curr] = val;
}

struct TreeNode *dequeue(struct TreeNode **queue, int *topFlg)
{
    struct TreeNode *node = queue[*topFlg];
    *topFlg += 1;
    return node;
}


int** levelOrder(struct TreeNode* root, int* returnSize, int** colSize)
{
    int **ret = NULL;
    *colSize = NULL;

    if(root == NULL)
    {
        *returnSize = 0;
        return ret;
    }

    struct TreeNode **queue = (struct TreeNode **)calloc(1,sizeof(*queue));
    int topFlg = -1;
    int curr = -1;
    int tmp,size,itr;

    enqueue(queue,&curr,root);
    ++topFlg;

    int level = 0;
    int prevNodes = 1;
    int newNodes = 0;

    ret = (int **)malloc(level+1*sizeof(*ret));
    ret[level] = (int *)malloc(prevNodes*sizeof(int));
    *colSize = (int *)malloc(level+1*sizeof(int));
    colSize[0][level] = prevNodes;

    struct TreeNode *node = NULL;
    while(topFlg <= curr)
    {
        itr = 0;
        while(itr < prevNodes)
        {
            node = dequeue(queue,&topFlg);
            ret[level][itr++] = node->val;

            if(node->left != NULL)
            {
                size = curr+1;
                ++newNodes;
                queue = (struct TreeNode **)realloc(queue,sizeof(*queue)*(size+1));
                enqueue(queue,&curr,node->left);
            }

            if(node->right != NULL)
            {
                size = curr+1;
                ++newNodes;
                queue = (struct TreeNode **)realloc(queue,sizeof(*queue)*(size+1));
                enqueue(queue,&curr,node->right);
            }
        }
        level += 1;

        if(newNodes > 0)
        {
            ret = (int **)realloc(ret,sizeof(*ret)*(level+1));
            colSize[0] = (int *)realloc(colSize[0],sizeof(int)*(level+1));
            prevNodes = newNodes;

            ret[level] = (int *)malloc(prevNodes*sizeof(int));
            colSize[0][level] = prevNodes;
        }
        newNodes = 0;

    }

    free(queue);
    *returnSize = level;
    return ret;
}
