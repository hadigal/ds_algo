/*
Given the root of a binary tree, each node has a value from 0 to 25 representing
the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b',
and so on.

Find the lexicographically smallest string that starts at a leaf of this tree
and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for
example, "ab" is lexicographically smaller than "aba".  A leaf of a node is a
node that has no children.)

Example 1:
Input: [0,1,2,3,4,3,4]
Output: "dba"

Example 2:
Input: [25,1,3,1,3,0,2]
Output: "adz"

Example 3:
Input: [2,2,1,null,1,0,null,0]
Output: "abc"

Note:
The number of nodes in the given tree will be between 1 and 8500.
Each node in the tree will have a value between 0 and 25.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;

void reverse(char **str, int len)
{
    int mid = len/2, itr1 = 0, itr2 = len-1;

    while(itr1 < mid)
    {
        char tmp = str[0][itr1];
        str[0][itr1++] = str[0][itr2];
        str[0][itr2--] = tmp;
    }

    return;
}

// logic is simple to traverse using preorder traversal and compare current string
// with previously stored string.  if less store it in smallest string.
void helper(Node *root,char **ret,char *path, char **smallest)
{
    if(root == NULL)
    {
        return;
    }

    char *np = NULL;
    int len = strlen(path);


    np = (char *)malloc((len+2)*sizeof(*np));
    snprintf(np,(len+2),"%s%c",path,(97+(char)root->val));

    if(root->left == NULL && root->right == NULL)
    {
        snprintf(*ret,len+2,"%s",np);
        reverse(ret,len+1);

        if(*smallest != NULL)
        {
            if(strcmp(*ret,*smallest) < 0)
            {
                snprintf(*smallest,len+2,"%s",*ret);
            }
        }
        else
        {
            sprintf(*smallest,"%s",*ret);
        }

        return;
    }

    helper(root->left,ret,np,smallest);
    helper(root->right,ret,np,smallest);
    free(np);
}

int height(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return (1+((lh > rh)?lh:rh));
}

char * smallestFromLeaf(struct TreeNode* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    int count  = 0, ht = height(root);

    char *ret = (char *)malloc((ht+1)*sizeof(*ret));
    char *smallest = (char *)malloc((ht+1)*sizeof(*smallest));

    helper(root,&ret,"",&smallest);
    free(ret);
    return smallest;
}
