/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// iterative
struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(1*sizeof(*newNode));
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->val = val;

    if(root == NULL)
    {
        return newNode;
    }

    struct TreeNode *itr = root;
    struct TreeNode *prev = NULL;

    while(itr != NULL)
    {
        prev = itr;

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
            //printf("duplicate\n");
            free(newNode);
            return root;
        }
    }

    if(prev->val > val)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right =  newNode;
    }

    return root;
}

//recursive
struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
  if(root == NULL)
  {
    root = (struct TreeNode *)malloc(1*sizeof(*root));
    root->val = val;
    root->right = NULL;
    root->left = NULL;
  }
  else if(root->val < val)
  {
    root->right = insertIntoBST(root->right,val);
  }
  else if(root->val > val)
  {
    root->left = insertIntoBST(root->left,val);
  }
  else
  {
    return root;
  }

  return root;
}
