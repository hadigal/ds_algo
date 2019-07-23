/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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

// used preorder traversal to find the root->leaf paths of the given B. tree.
// used the count to create an array of char ptr to hold the paths string
// could have used asprintf() instead of snprintf() here but was not supported on LC.
// using asprintf() we can pass ptr to str as 1st arg, second arg is the string
// format we want to store in that array and 3rd are the variadic args to store in
// string format -> eg: asprintf(&str,"%s%s",str2,str3);
// Using asprintf is safer than snprintf where asprintf will dynamically allocate
// memory for the new string based on input format of string and then copy it to the
// array. Here I am trying to mock asprintf using snprintf by creating 2 char arrays
// to store the strings.
void countPath(Node *root, int *count)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        ++*count;
        return;
    }

    countPath(root->left,count);
    countPath(root->right,count);
}

void helper(Node *root, char ***ret, int *idx, char *path)
{
    if(root == NULL)
    {
        return;
    }

    char *nP = NULL;
    char *curr = (char *)malloc(10*sizeof(*curr));
    snprintf(curr,10,"%d",root->val);
    int len = strlen(curr)+strlen(path);

    if(root->left == NULL && root->right == NULL)
    {
        ret[0][*idx] = (char *)malloc((len+1)*sizeof(char));
        snprintf(ret[0][*idx],len+1,"%s%s",path,curr);
        ++*idx;
        return;
    }

    nP = (char *)malloc((len+3)*sizeof(*nP));
    snprintf(nP,len+3,"%s%s->",path,curr);
    helper(root->left,ret,idx,nP);
    helper(root->right,ret,idx,nP);

    free(nP);
}


char ** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int count = 0;
    countPath(root,&count);

    char **ret = (char *)malloc(count*sizeof(*ret));
    *returnSize = count;

    int idx = 0;
    helper(root,&ret,&idx,"");

    return ret;
}
