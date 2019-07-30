/*
Given a binary search tree (BST) with duplicates, find all the mode(s)
(the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.


For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2


return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the
implicit stack space incurred due to recursion does not count).
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeNode Node;


// logic is simple to compute the count of max repeating node val using dfs inorder iterator.
// using this max count; during secind inorder dfs iteration store the value to
//a int arr which indexed using a ptr var hold count of idx.
void dfs(Node *root, int *prev, int *curr, int *max, int *len)
{
    if(root == NULL)
    {
        return;
    }

    dfs(root->left,prev,curr,max,len);

    if(*prev != INT_MIN)
    {
        if(*prev == root->val)
        {
            ++*curr;
        }
        else
        {
            *curr = 1;
        }

        *max = ((*max > *curr)?(*max):(*curr));
        //*prev = root->val;
    }
    else
    {
        //*prev = root->val;
        *curr = 1;
        *max = 1;
    }

    *prev = root->val;
    ++*len;

    dfs(root->right,prev,curr,max,len);
}

void mode(Node *root, int **ret, int *len, int *prev,int *curr, int max)
{
    if(root == NULL)
    {
        return;
    }

    mode(root->left,ret,len,prev,curr,max);

    if(root->val == *prev)
    {
        ++*curr;
    }
    else
    {
        *curr = 1;
    }

    if(*curr == max)
    {
        ret[0][*len] = root->val;
        ++*len;
    }

    *prev = root->val;
    mode(root->right,ret,len,prev,curr,max);
}

int* findMode(struct TreeNode* root, int* returnSize)
{
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int len = 0;
    int prev = INT_MIN;
    int curr = 0;
    int max = 0;

    dfs(root,&prev,&curr,&max,&len);
    int *ret = (int *)malloc(len*sizeof(*ret));
    *returnSize = 0;
    prev = INT_MIN;
    curr = 0;

    mode(root,&ret,returnSize,&prev,&curr,max);
    return ret;
}
