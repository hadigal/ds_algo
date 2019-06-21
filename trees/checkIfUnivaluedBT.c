/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// used recursive preorder approach. check if value of each node is equal
// to TreeRoot->val; if node equal return false else iterate left tree and then
// right tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool dfsHelper(struct TreeNode *root, int val)
{
    if(root == NULL)
    {
        return true;
    }

//     if(*prev == INT_MIN)
//     {
//         *prev = root->val;
//     }
//     else
//     {
//         if(root->val != *prev)
//         {
//             //printf("root->val:%d, prev:%d\n",root->val,*prev);
//             return false;
//         }
//         else
//         {
//             *prev = root->val;
//         }
//     }

    if(root->val != val)
    {
        return false;
    }
    else
    {
        return (dfsHelper(root->left,val) && dfsHelper(root->right,val));
    }

    //return (dfsHelper(root->left,prev) && dfsHelper(root->right,prev));
}


bool isUnivalTree(struct TreeNode* root)
{
    if(root == NULL)
    {
        return true;
    }

    //int prev = INT_MIN;
    bool ret = dfsHelper(root, root->val);

    return ret;
}
