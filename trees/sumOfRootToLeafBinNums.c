/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents
a binary number starting with the most significant bit.  For example, if the path
is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from
the root to that leaf.

Return the sum of these numbers.

Example 1:
Input: [1,0,1,0,1,0,1]
Output: 22

Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22


Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// logic is to use a single char array to store bin num from root->leaf; at the
// leaf node find the int equivalent of the bin num and add it to sum. Now return
// from this root node to continue to root's right leaf node. 
int height(struct TreeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return (1 + ((lh > rh)?lh:rh));
}

void dfsHelper(struct TreeNode *root, char *num, int idx, int *sum)
{
    if(root == NULL)
    {
        return;
    }

    num[idx] = 48+root->val;
    if(root->left == NULL && root->right == NULL)
    {
        int itr = 0;
        int tmp = 0;
        while(itr <= idx)
        {
            int val = num[itr] - 48;
            if(val == 1)
            {
                tmp += (1 << (idx-itr));
            }
            ++itr;
        }

        *sum += tmp;
        return;
    }

    dfsHelper(root->left,num,idx+1,sum);
    dfsHelper(root->right,num,idx+1,sum);
}

int sumRootToLeaf(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int ht = height(root);
    char *num = (char *)malloc((ht+1)*sizeof(*num));
    int sum = 0;

    int idx = 0;

    dfsHelper(root,num,idx,&sum);
    free(num);

    return sum;
}
