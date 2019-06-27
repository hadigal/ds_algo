/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/


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

typedef struct TreeNode Node;

void push(Node ***queue, int *curr, Node *val)
{
    if(*curr > -1)
    {
        int sz = *curr + 1;
        *queue = (Node **)realloc(*queue,sizeof(Node *)*(sz+1));
    }

    ++*curr;
    queue[0][*curr] = val;
    return;
}

Node *pop(Node **queue, int *tf)
{
    Node *node = queue[*tf];
    ++*tf;
    return node;
}

int** levelOrderBottom(struct TreeNode* root, int* retSize, int** retColSize)
{
    if(root == NULL)
    {
        *retSize = 0;
        *retColSize = NULL;
        return NULL;
    }

    int **ret = (int **)malloc(1*sizeof(*ret));
    int level = 0, tf = -1, curr = -1;
    int prev = 1, next = 0, itr = 0;
    Node **queue = (Node **)malloc(1*sizeof(*queue));
    Node *node = NULL;

    push(&queue,&curr,root);
    ++tf;
    *retColSize = (int *)malloc(1*sizeof(int));
    retColSize[0][level] = prev;
    ret[level] = (int *)malloc(prev*sizeof(int));

    while(tf <= curr)
    {
        while(itr < prev)
        {
            node = pop(queue,&tf);
            ret[level][itr] = node->val;

            if(node->left != NULL)
            {
                push(&queue,&curr,node->left);
                ++next;
            }

            if(node->right != NULL)
            {
                push(&queue,&curr,node->right);
                ++next;
            }

            ++itr;
        }

        if(next > 0)
        {
            ++level;
            ret = (int **)realloc(ret,sizeof(*ret)*(level+1));
            ret[level] = (int *)malloc(next*sizeof(int));

            *retColSize = (int *)realloc(*retColSize,sizeof(int)*(level+1));
            retColSize[0][level] = next;
            prev = next;
            itr = 0;
            next = 0;
        }
    }

    itr = 0;
    int end = level;
    int mid = (level + 1)/2;

    while(itr < mid)
    {
        int *tmp = ret[itr];
        ret[itr] = ret[end];
        ret[end] = tmp;

        int cTmp = retColSize[0][itr];
        retColSize[0][itr] = retColSize[0][end];
        retColSize[0][end] = cTmp;

        ++itr;
        --end;
    }

    *retSize = level+1;
    free(queue);
    return ret;
}
