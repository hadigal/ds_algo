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

// recursive solutiom
void dfsHelper(Node *root, int **ret, int *len, int level, int *maxL)
{
    if(root == NULL)
    {
        return;
    }

    // check if the current level is greater than maxL visited
    if(*maxL < level)
    {
        // if curr level > maxLevel visited
        // store the val of the node in an int array
        if(*len > 0)
        {
            ret[0] = (int *)realloc(ret[0],sizeof(int)*(*len+1));
        }
        ret[0][*len] = root->val;
        ++*len;
        // update the max level to current level
        *maxL = level;
    }

    // now since we want the right side view first traverse the right subtree and
    // then left sub tree
    dfsHelper(root->right,ret,len,level+1,maxL);
    dfsHelper(root->left,ret,len,level+1,maxL);

    return;
}


int* rightSideView(struct TreeNode* root, int* returnSize)
{
    int *ret = NULL;
    if(root == NULL)
    {
        *returnSize = 0;
        return ret;
    }

    ret = (int *)malloc(1*sizeof(*ret));
    int len = 0;
    int level = 0;
    int maxL = 0;
    dfsHelper(root,&ret,&len,level+1,&maxL);

    *returnSize = len;
    return ret;
}
