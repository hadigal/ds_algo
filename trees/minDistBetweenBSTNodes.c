/************************ LC: 783 min distance between bst node ****************
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \
    1   3

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.
*******************************************************************************/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// used InOrder algo to find the min distance between BST nodes
void dfsInOrder(struct TreeNode *root,int *prev,int *min)
{
    if(root == NULL)
    {
        return;
    }

    dfsInOrder(root->left,prev,min);

    if(root->val != *prev)
    {
        int tmp = abs(root->val - *prev);
        *min = ((tmp < *min)?tmp:*min);
    }
    *prev = root->val;
    dfsInOrder(root->right,prev,min);
}

int minDiffInBST(struct TreeNode* root)
{
    //struct TreeNode *prev = NULL;
    int prev = root->val;
    int min = INT_MAX;

    dfsInOrder(root,&prev,&min);

    return min;
}
