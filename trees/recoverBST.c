/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// logic is to find the large node first and the small node value which are out of
// order. If small node is node val is not found in first iteration go for another
// inOrder iteration with prev node reset to INT_MIN and with large node val already Found
// get the small node value. Once the small node value is found replace it with large node value
// and store the value small node. This way now the large node value is in its correct order.
// ALso now we have 2 node with large node value in tree iterate the tree
// again(3rd time if small node value was not found in 1st iteration) inOrder and
// replace the 1st node found with large val with the stored small value.
void dfsHelper(struct TreeNode *root, int *sm, int *lg, int *prev,int flg)
{
    if(root == NULL)
    {
        return;
    }

    dfsHelper(root->left,sm,lg,prev,flg);

    if(flg == 0)
    {
        if(*prev == INT_MIN)
        {
            *prev = root->val;
        }
        else
        {
            if(root->val < *prev && *lg == INT_MIN)
            {
                *lg = *prev;
                *prev = root->val;
            }
            else if(root->val < *prev && *lg != INT_MIN)
            {
                *sm = root->val;
                root->val = *lg;
                return;
            }
            else
            {
                *prev = root->val;
            }
        }
    }
    else
    {
        if(root->val == *lg)
        {
            root->val = *sm;
            *lg = INT_MIN;
            return;
        }
    }
    dfsHelper(root->right,sm,lg,prev,flg);
}

void recoverTree(struct TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    int sm = INT_MIN, lg = INT_MIN, prev = INT_MIN;

    dfsHelper(root,&sm,&lg,&prev,0);

    if(sm == INT_MIN)
    {
        prev = INT_MIN;
        dfsHelper(root,&sm,&lg,&prev,0);
    }

    dfsHelper(root,&sm,&lg,&prev,1);

    return;
}
