/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// This is a O(n+n) time and O(n) space solution
// This can be optimized!!
void dfsHelper(struct TreeNode *root, int **arr, int *size)
{
    if(root == NULL)
    {
        return;
    }

    dfsHelper(root->left,arr,size);
    if(*size > 0)
    {
        *arr = (int *)realloc(*arr,sizeof(int)*(*size+1));
    }
    arr[0][*size] = root->val;
    *size += 1;
    dfsHelper(root->right,arr,size);
}


bool isValidBST(struct TreeNode* root)
{
    if(root == NULL)
    {
        return true;
    }
    int *arr = (int *)malloc(1*sizeof(*arr));
    int size = 0;
    bool flg = true;
    dfsHelper(root,&arr, &size);

    for(size_t itr = 0; itr < size-1; ++itr)
    {
        if(arr[itr] >= arr[itr+1])
        {
            flg = false;
            break;
        }
    }

    free(arr);
    return flg;
}
