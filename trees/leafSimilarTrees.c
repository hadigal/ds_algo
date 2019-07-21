/*
Consider all the leaves of a binary tree.  From left to right order, the values
of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the
same.

Return true if and only if the two given trees with head nodes root1 and root2
are leaf-similar.

Note:

Both of the given trees will have between 1 and 100 nodes.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void leafExt(struct TreeNode *root, int **arr, int *len)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        // if(*len > 0)
        // {
        //     *arr = (int *)realloc(*arr,sizeof(int)*(*len+1));
        // }
        arr[0][*len] = root->val;
        ++*len;
    }

    leafExt(root->left,arr,len);
    leafExt(root->right,arr,len);

    return;
}

void dfsHelper(struct TreeNode *root, bool *ret, int *idx, int len, int *arr)
{
    if(root == NULL)
    {
        return;
    }

    if(*ret == true)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(*idx >= len || arr[*idx] != root->val)
            {
                *ret = false;
                return;
            }
            else
            {
                ++*idx;
            }
        }
    }
    else
    {
        return;
    }

    dfsHelper(root->left,ret,idx,len,arr);
    dfsHelper(root->right,ret,idx,len,arr);

    return;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
    if(root1 == NULL || root2 == NULL)
    {
        return false;
    }

    int *arr = (int *)malloc(100*sizeof(*arr));
    int len = 0, idx = 0;
    leafExt(root1,&arr,&len);

    bool ret = true;
    dfsHelper(root2,&ret,&idx,len,arr);

    free(arr);
    return ret;
}
