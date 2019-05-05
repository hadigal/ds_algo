/****************************** LC 108 **************************************
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in
which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*****************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;

TreeNode *create(int val)
{
    TreeNode *node = (TreeNode *)malloc(1*sizeof(*node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void createBST(TreeNode **root, int *arr, int lIdx, int rIdx)
{
    if((rIdx < lIdx) || (lIdx > rIdx))
    {
        return;
    }

    int mid = (lIdx+rIdx)/2;
    int val = arr[mid];
    *root = create(val);
    createBST(&((*root)->left),arr,lIdx,mid-1);
    createBST(&((*root)->right),arr,mid+1,rIdx);
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    TreeNode *root = NULL;

    createBST(&root,nums,0,numsSize-1);

    return root;
}
