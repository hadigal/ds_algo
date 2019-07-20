/*
Given a binary search tree, rearrange the tree in in-order so that the leftmost
node in the tree is now the root of the tree, and every node has no left child
and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9
Note:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// logic is to traverse inorder and store the prev node left child - null and right
// child - curr node. at the end of iteration repeat the same thing

void dfsHelper(struct TreeNode *root, struct TreeNode **newRoot, struct TreeNode **prev)
{
    if(root == NULL)
    {
        return;
    }

    dfsHelper(root->left,newRoot,prev);

    if(*newRoot != NULL)
    {
        if(*prev != NULL)
        {
            (*prev)->left = NULL;
            (*prev)->right = root;
        }
    }
    else
    {
        *newRoot = root;
    }

    *prev = root;

    dfsHelper(root->right,newRoot,prev);
}

struct TreeNode* increasingBST(struct TreeNode* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    struct TreeNode *newRoot = NULL, *prev = NULL;

    dfsHelper(root,&newRoot,&prev);

    prev->left = NULL;
    return newRoot;
}
