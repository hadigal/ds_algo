/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//void findBottomLeft(struct TreeNode *root, int level, int *maxL, struct TreeNode **bL)
void findBottomLeft(struct TreeNode *root, int level, int *maxL, int *bL)
{
    if(root == NULL)
    {
        return;
    }

    // check if curr level is > maxLevel
    // if yes store the value of curr node to value of ptr bL
    if(*maxL < level)
    {
        *maxL = level;
        // if(root->left == NULL && root->right == NULL)
        // {
        //     *bL = root;
        // }
        *bL = root->val;
    }

    // recursively iterate the left subtree first then right since we want the left
    // bottom leaf node;
    findBottomLeft(root->left,level+1,maxL,bL);
    findBottomLeft(root->right,level+1,maxL,bL);
}

int findBottomLeftValue(struct TreeNode* root)
{
    //struct TreeNode *bL = NULL;
    int bL;
    int maxL = 0;
    int level = 0;
    findBottomLeft(root,level+1,&maxL,&bL);
    return bL;
    //return bL->val;
}
