/**************************** LC 98 *****************************************
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
****************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// awesome o(log n) time and o(1) space solution
// use in InOrder
// init the prev object with INT_MAX+1 value --> i.e 2147483648 (x64 and gcc)
// while iterating inorder if ret(which is bool type) is true or *prev is INT_MAX+1 --> is generally until we reach 1st leaf node
//update ptr to prev obj with root->val
// else if root->val <= *prev and *prev != INT_MAX +1 update ptr to ret with false and return no need to iterate further!!
// this reduces execution time from 104 ms for previous o(n) solution to 8ms

void dfsHelper(struct TreeNode *root, long int *prev, bool *ret)
{
    if(root == NULL)
    {
        return;
    }

    dfsHelper(root->left,prev,ret);

    if(*ret == true)
    {
        if(root->val > *prev || *prev == 2147483648)
        {
            //*ret = true;
            *prev = root->val;
        }
        else if(*prev != 2147483648 && root->val <= *prev)
        {
            *ret = false;
            return;
        }
    }
    dfsHelper(root->right,prev,ret);
}


bool isValidBST(struct TreeNode* root)
{
    if(root == NULL)
    {
        return true;
    }

    bool flg = true;
    long int prev = 2147483648;
    dfsHelper(root,&prev, &flg);

    return flg;
}



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
