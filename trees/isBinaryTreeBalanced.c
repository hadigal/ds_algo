/************************ LC 110 *****************************
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
**************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lt = height(root->left);
    int rt = height(root->right);

    int ret = (lt > rt)?lt:rt;

    return (ret+1);
}

bool isBalanced(struct TreeNode* root)
{
    if(root == NULL)
    {
        return true;
    }

    int left = height(root->left);
    int right = height(root->right);

    if(abs(left - right) <= 1)
    {
        if(isBalanced(root->left) ==  true &&  isBalanced(root->right) == true)
        {
            return true;
        }
    }

    return false;
}
