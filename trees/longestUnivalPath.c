/*
Given a binary tree, find the length of the longest path where each node in the
path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges
between them.



Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2



Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2



Note: The given binary tree has not more than 10000 nodes. The height of the
tree is not more than 1000.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;


// logic is to traverse using postorder traversal; check if left/right child exists
// if yes then add 1 to their respected count returned during traversal else store
// zero. Before return check if val at addr held by max ptr is < (lm+rm) store new val
// the addr. return the value (lm > rm)?lm:rm;
int dfs(Node *root,int *max)
{
    if(root == NULL)
    {
        return 0;
    }

    int lm = dfs(root->left,max);
    int rm = dfs(root->right,max);

    if(root->left != NULL && root->left->val == root->val)
    {
        lm += 1;
    }
    else
    {
        lm = 0;
    }

    if(root->right != NULL && root->right->val == root->val)
    {
        rm += 1;
    }
    else
    {
        rm = 0;
    }

    *max = (*max > (lm+rm))?(*max):(lm+rm);
    return ((lm > rm)?lm:rm);
}


int longestUnivaluePath(struct TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    int max = 0;
    dfs(root,&max);

    return max;
}
