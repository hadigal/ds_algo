/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    struct TreeNode *rt = invertTree(root->right);
    struct TreeNode *lt = invertTree(root->left);
    root->left = rt;
    root->right = lt;

    return root;
}
