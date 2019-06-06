/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// used recursive inOrder tranversal solution
void dfsHelper(struct TreeNode *root, int *sum, struct TreeNode *prev)
{
    if(root == NULL)
    {
        return;
    }
    // traverse in order left->root->right
    // at each step check pass curr node as ptr to prev node
    dfsHelper(root->left,sum,root);
    // use prev node to check if curr node is left node of current node
    if((prev != NULL && prev->left == root))
    {
        // if yes then check if the curr node is a leaf node
        if(root->left == NULL && root->right == NULL)
        {
            // if yes add the value curr node to value at sum ptr
            *sum += root->val;
        }
    }

    dfsHelper(root->right,sum,root);
}

int sumOfLeftLeaves(struct TreeNode* root)
{
    if(root == NULL || (root->right == NULL && root->left == NULL))
    {
        return 0;
    }

    struct TreeNode *prev = NULL;
    int sum = 0;
    dfsHelper(root,&sum,prev);

    return sum;
}
