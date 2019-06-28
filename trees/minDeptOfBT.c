/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    int ret;

    if(rh == 0 || lh == 0)
    {
        ret = lh+rh+1;
    }
    else
    {
        ret = ((lh < rh)?(lh+1):(rh+1));
    }

    return ret;
}
