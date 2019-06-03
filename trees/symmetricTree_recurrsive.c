/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Recursive approach
bool helper(struct TreeNode *r1, struct TreeNode *r2)
{
    if(r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if(r1 != NULL && r2 != NULL && r1->val == r2->val)
    {
        if(helper(r1->left,r2->right) && helper(r1->right,r2->left))
        {
            return true;
        }
    }
    return false;
}

bool isSymmetric(struct TreeNode* root)
{
    if(root == NULL)
    {
        return true;
    }
    return helper(root->left,root->right);
}
