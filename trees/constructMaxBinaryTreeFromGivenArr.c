/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;

// implemented a recursive solution where we find the max elements at  each recursive
// call. First find the idx of the max element in the array; now recursively call
// the left sub array using ptr to lIdx and rIdx, for left sub array the rIdx is
// maxItr - 1 and for right sub array the lIdx is maxItr+1. If the lIdx and rIdx
// are equal just return the new created node else if lIdx > rIdx return NULL

int findMax(int *arr, int lIdx, int rIdx)
{
    int max = arr[lIdx];
    int maxItr = lIdx;
    int itr = lIdx+1;

    while(itr <= rIdx)
    {
        if(arr[itr] > max)
        {
            max = arr[itr];
            maxItr = itr;
        }
        ++itr;
    }

    return maxItr;
}

Node *createNode(int val)
{
    Node *node = (Node *)malloc(1*sizeof(*node));
    node->val = val;
    node->right = NULL;
    node->left = NULL;

    return node;
}

Node *helper(int *arr, int lIdx, int rIdx)
{
    if(lIdx > rIdx)
    {
        return NULL;
    }

    int maxItr = findMax(arr,lIdx,rIdx);
    Node *node = createNode(arr[maxItr]);
    if(lIdx == rIdx)
    {
        return node;
    }

    node->left = helper(arr,lIdx,maxItr-1);
    node->right = helper(arr,maxItr+1,rIdx);

    return node;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int len)
{
    Node *root = NULL;
    if(nums == NULL || len == 0)
    {
        return NULL;
    }

    int maxItr = findMax(nums,0,len-1);
    root = createNode(nums[maxItr]);

    root->left = helper(nums,0,maxItr-1);
    root->right = helper(nums,maxItr+1,len-1);

    return root;
}
