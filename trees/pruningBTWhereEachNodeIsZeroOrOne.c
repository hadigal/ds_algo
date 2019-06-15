/*
We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.

Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

Example 1:
Input: [1,null,0,0,1]
Output: [1,null,0,null,1]

Explanation:
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

Example 2:
Input: [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

Example 3:
Input: [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]

Note:

The binary tree will have at most 100 nodes.
The value of each node will only be 0 or 1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// Time: O(N)and Space: O(1) if is recursive call stack is ignored
// logic is to use recursive approach to find the sum of left and right subtree for each node
// if the sum of left/right subtree is mark the left and right child of current
// node as NULL.

// Also to find the sum of left sub tree and right subtree add the val of current
// node with value of left subtree and right subtree and return the value. If node is
// NULL return 0
int dfsHelper(struct TreeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lval = dfsHelper(root->left);
    int rval = dfsHelper(root->right);

    if(lval == 0)
    {
        root->left = NULL;
    }

    if(rval == 0)
    {
        root->right = NULL;
    }

    return (lval+rval+root->val);
}

struct TreeNode* pruneTree(struct TreeNode* root)
{
    if(root == NULL)
    {
        return root;
    }

    dfsHelper(root);

    return root;
}
