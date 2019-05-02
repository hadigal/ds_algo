/********************************** LC: 103 *******************************
Given a binary tree, return the zigzag level order traversal of its nodes' values.
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
typedef struct TreeNode TreeNode;

void enqueue(TreeNode **queue, TreeNode *val, int *curr)
{
    *curr += 1;
    queue[*curr] = val;
    return;
}

TreeNode *dequeue(TreeNode **queue, int *topFlg)
{
    TreeNode *node = queue[*topFlg];
    *topFlg += 1;
    return node;
}

// using the previously implemented logic to store the node values at each level
// in an 2D array and invert the values for odd indexed values to have values stored
// in zigzag format
void invert(int **arr, int len)
{
    int mid = len/2, temp;
    for(size_t itr = 0; itr < mid; ++itr)
    {
        temp = arr[0][len-1-itr];
        arr[0][len-1-itr] = arr[0][itr];
        arr[0][itr] = temp;
    }
}


int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** colSize)
{
    int **ret = NULL;
    if(root == NULL)
    {
        *returnSize = 0;
        *colSize = NULL;
        return ret;
    }

    TreeNode **queue = NULL;
    int prevNodes = 1, nextNodes = 0;
    int curr = -1, topFlg = -1;
    int size = curr+1, level = 0, itr;
    queue = (TreeNode **)malloc((size+1)*sizeof(*queue));
    enqueue(queue,root,&curr);
    ++topFlg;

    *colSize = (int *)malloc((level+1)*sizeof(int));
    colSize[0][level] = prevNodes;
    ret = (int **)malloc((level+1)*sizeof(*ret));
    ret[level] = (int *)malloc((prevNodes)*sizeof(*ret));

    TreeNode *node = NULL;

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
                queue = (TreeNode **)realloc(queue,sizeof(*queue)*(size+1));
                enqueue(queue,node->left,&curr);
                ++nextNodes;
            }

            if(node->right != NULL)
            {
                size = curr+1;
                queue = (TreeNode **)realloc(queue,sizeof(*queue)*(size+1));
                enqueue(queue,node->right,&curr);
                ++nextNodes;
            }
        }

        if(prevNodes > 1 && ((level % 2) != 0))
        {
            invert(&ret[level],prevNodes);
        }

        if(nextNodes > 0)
        {
            prevNodes = nextNodes;
            ++level;
            colSize[0] = (int *)realloc(colSize[0],(level+1)*sizeof(int));
            colSize[0][level] = prevNodes;
            ret = (int **)realloc(ret,sizeof(*ret)*(level+1));

            *(ret+level) = (int *)malloc(sizeof(int)*prevNodes);
            nextNodes = 0;
        }
    }

    free(queue);
    *returnSize = level+1;
    return ret;
}
