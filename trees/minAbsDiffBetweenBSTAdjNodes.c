/********************************** leetcode pb: 538 *************************
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).


Note: There are at least two nodes in this BST.
******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfsInOrder(struct TreeNode *root,struct TreeNode **prev,int *min)
{
    if(root == NULL)
    {
        return;
    }

    dfsInOrder(root->left,prev,min);

    if(*prev != NULL)
    {
        int tmp = root->val - (*prev)->val;
        *min = ((tmp < *min)?tmp:*min);
    }
    *prev = root;

    dfsInOrder(root->right,prev,min);
}

int getMinimumDifference(struct TreeNode* root)
{
    struct TreeNode *prev = NULL;
    int min = INT_MAX;

    dfsInOrder(root,&prev,&min);

    return min;
}
