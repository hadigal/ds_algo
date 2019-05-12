/****************************** lc 145 *****************************
145. Binary Tree Postorder Traversal
Hard

856

41

Favorite

Share
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
*******************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// used to two stacks to implement
// iteratively traverse the given tree with modified preorderTraversal (left first in stack)
// Then store every poped node in another stack
// once all nodes are traversed store the stack2 elements data in 1d array

typedef struct TreeNode TreeNode;

void push(TreeNode **stack,TreeNode *val, int *topFlg)
{
    *topFlg += 1;
    stack[*topFlg] = val;
    return;
}

TreeNode *pop(TreeNode **stack, int *topFlg)
{
    TreeNode *node = stack[*topFlg];
    *topFlg -= 1;
    return node;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *ret = NULL;
    if(root == NULL)
    {
        *returnSize = 0;
        return ret;
    }

    TreeNode **stack = (TreeNode **)malloc(1*sizeof(*stack));
    TreeNode **rootStack = (TreeNode **)malloc(1*sizeof(*rootStack));

    int topFlg1 = -1, curr = 0;
    int topFlg2 = -1;

    int nc = 0;

    push(stack,root,&topFlg1);

    TreeNode *tmp= NULL;
    while(topFlg1 > -1)
    {
        tmp = pop(stack,&topFlg1);

        if(topFlg2 > -1)
        {
            int size = topFlg2 + 1;
            rootStack = (TreeNode **)realloc(rootStack,sizeof(*rootStack)*(size+1));
        }
        push(rootStack,tmp,&topFlg2);

        if(tmp->left != NULL)
        {
            if(topFlg1 > -1)
            {
                int size = topFlg1 + 1;
                stack = (TreeNode **)realloc(stack,sizeof(*stack)*(size+1));
            }
            push(stack,tmp->left,&topFlg1);
        }

        if(tmp->right != NULL)
        {
            if(topFlg1 > -1)
            {
                int size = topFlg1 + 1;
                stack = (TreeNode **)realloc(stack,sizeof(*stack)*(size+1));
            }
            push(stack,tmp->right,&topFlg1);
        }
    }

    nc = topFlg2 + 1;
    ret = (int *)malloc((nc+1)*sizeof(*ret));
    int itr = 0;
    while(topFlg2 > -1)
    {
        TreeNode *retNode = pop(rootStack,&topFlg2);
        ret[itr++] = retNode->val;
    }
    *returnSize = nc;

    free(stack);
    free(rootStack);
    return ret;
}
