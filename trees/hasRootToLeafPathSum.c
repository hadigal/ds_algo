/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// logic is to iterate preorder approach check if current node is leaf node,
// if yes check if sum is equal to root->val if yes return true else false. if
// not leaf node substract sum and root->Val and move to next sub tree - right or left
bool hasPathSum(struct TreeNode* root, int sum)
{
    if(root == NULL)
    {
        return false;
    }

    if(root->left == NULL && root->right == NULL)
    {
        if(sum == root->val)
        {
            return true;
        }

        return false;
    }

    return (hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val));
}
