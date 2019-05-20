/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// recursive
struct TreeNode* searchBST(struct TreeNode* root, int val)
{
  if(root == NULL)
  {
    return root;
  }

  if(root->val < val)
  {
    return searchBST(root->right,val);
  }
  else if(root->val > val)
  {
    return searchBST(root->left,val);
  }
  else
  {
    return root;
  }
}

// iterative solution
struct TreeNode* searchBST(struct TreeNode* root, int val)
{
    struct TreeNode *itr = root;
    while(itr != NULL)
    {
        if(itr->val < val)
        {
            itr = itr->right;
        }
        else if(itr->val > val)
        {
            itr = itr->left;
        }
        else
        {
            return itr;
        }
    }

    return itr;
}
