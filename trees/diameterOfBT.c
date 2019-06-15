/*
Given a binary tree, you need to compute the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two
nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges
between them.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// basically find the height of the btree and use an variable to store the max height
// at each node
// this is computed by adding the left height and right height and 1 and check
// whether that value is > than prev height. Start by initializing the height
// with INT_MIN 
int htHelper(struct TreeNode *root, int *ht)
{
    if(root == NULL)
    {
        return 0;
    }

    int lh = htHelper(root->left,ht);
    int rh = htHelper(root->right,ht);

    int tmp = lh+rh;

    *ht = (tmp > *ht)?tmp:*ht;

    int maxH = (lh > rh)?lh:rh;
    maxH += 1;

    return maxH;
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int ht = INT_MIN;
    htHelper(root,&ht);

    return ht;
}
