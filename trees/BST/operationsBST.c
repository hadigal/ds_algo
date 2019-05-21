#include "BST.h"

TreeNode *createNode(int val)
{
  TreeNode *node = (TreeNode *)calloc(1,sizeof(*node));
  node->val = val;
  node->left = NULL;
  node->right = NULL;

  return node;
}

TreeNode *search(TreeNode *root, int key)
{
  if(root == NULL)
  {
    return root;
  }

  TreeNode *itr = root, *ret = NULL;

  while(itr != NULL)
  {
    if(itr->val == key)
    {
      ret = itr;
      break;
    }
    else if(itr->val < key)
    {
      itr = itr->right;
    }
    else
    {
      itr = itr->left;
    }
  }

  return ret;
}

TreeNode *insert(TreeNode *root, int key)
{
  if(root == NULL)
  {
    root = (TreeNode *)malloc(1*sizeof(*root));
    root->val = key;
    root->right = NULL;
    root->left = NULL;

    return root;
  }

  //TreeNode *new = (TreeNode *)malloc(1*sizeof(*new));
  TreeNode *new;

  TreeNode *itr = root, *prev = NULL;

  while(itr != NULL)
  {
    prev = itr;

    if(itr->val < key)
    {
      itr = itr->right;
    }
    else if(itr->val > key)
    {
      itr = itr->left;
    }
    else
    {
      printf("duplicates\n");
      return root;
    }
  }

  // new->val = key;
  // new->left = NULL;
  // new->right = NULL;

  new = createNode(key);

  if(prev->val < key)
  {
    prev->right = new;
  }
  else
  {
    prev->left = new;
  }

  return root;
}

TreeNode *delete(TreeNode *root, int key)
{
  if(root == NULL)
  {
    return root;
  }

  // for node itr
  TreeNode *itr = root, *prev = NULL;
  // for iterating to find the appropriate new child node for the node to be deleted
  //which has 2 child nodes
  TreeNode *itr2, *prev2, *child = NULL;

  while(itr != NULL)
  {
    if(itr->val == key)
    {
      break;
    }

    prev = itr;
    if(itr->val < key)
    {
      itr = itr->right;
    }
    else
    {
      itr = itr->left;
    }
  }

  if(itr == NULL)
  {
    printf("key not found\n");
    return root;
  }

  if(itr->left != NULL && itr->right != NULL)
  {
    // find the appropriate node from the right side of tree
    itr2 = itr->right;
    prev2 = itr;

    // iterating only the left child nodes to find the next child node for curr node
    while(itr2->left != NULL)
    {
      prev2 = itr2;
      itr2 = itr2->left;
    }

    itr->val = itr2->val;
    prev = prev2;
    itr = itr2;
  }

  if(itr->left != NULL)
  {
    child = itr->left;
  }
  else
  {
    child = itr->right;
  }

  if(prev == NULL)
  {
    root = child;
  }
  else if(prev->left == itr)
  {
    prev->left = child;
  }
  else
  {
    prev->right = child;
  }

  free(itr);
  return root;
}

void preOrder(TreeNode *root)
{
  if(root == NULL)
  {
    return;
  }

  printf("node[%p]:%d\n",root,root->val);
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(TreeNode *root)
{
  if(root == NULL)
  {
    return;
  }

  postOrder(root->left);
  postOrder(root->right);
  printf("node[%p]:%d\n",root,root->val);
}

void inOrder(TreeNode *root)
{
  if(root == NULL)
  {
    return;
  }

  inOrder(root->left);
  printf("node[%p]:%d\n",root,root->val);
  inOrder(root->right);
}

TreeNode *min(TreeNode *root)
{
  if(root == NULL)
  {
    return root;
  }

  TreeNode *itr = root;

  while(itr->left != NULL)
  {
    itr = itr->left;
  }

  return itr;
}

TreeNode *max(TreeNode *root)
{
  if(root == NULL)
  {
    return root;
  }

  TreeNode *itr = root;

  while(itr->right != NULL)
  {
    itr = itr->right;
  }

  return itr;
}
