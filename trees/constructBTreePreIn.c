/*********************************************************
* use inorder and preorder array
**********************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
}TreeNode;

static inline TreeNode *create(int val)
{
  TreeNode *node = (TreeNode *)calloc(1,sizeof(*node));

  node->val = val;
  node->left = NULL;
  node->right = NULL;

  return node;
}

TreeNode *treeConstruct(int *inOrder, int *preOrder, int start, int end)
{
  static int pre = 0;
  if(start > end)
  {
    return NULL;
  }

  int rootVal = preOrder[pre++];
  printf("rootVal:%d\n",rootVal);

  TreeNode *node = create(rootVal);
  if(start == end)
  {
    return node;
  }
  //++preOrderr

  size_t itr;
  for(itr = start; itr < end; ++itr)
  {
    if(inOrder[itr] == rootVal)
    {
      break;
    }
  }

  node->left = treeConstruct(inOrder,preOrder,start,itr-1);
  node->right = treeConstruct(inOrder,preOrder,itr+1,end);

  return node;
}

TreeNode *treeConstructPostAndIn(int *inOrder, int *postOrder, int start, int end, int *post)
{
  //static int post = 4;
  if(start > end)
  {
    return NULL;
  }

  int rootVal = postOrder[*post];
  (*post)--;
  printf("rootVal:%d\n",rootVal);
  TreeNode *node = create(rootVal);
  if(start == end)
  {
    return node;
  }

  size_t itr;

  for(itr = start; itr <= end; ++itr)
  {
    if(inOrder[itr] == rootVal);
    {
      break;
    }
  }

  node->left = treeConstructPostAndIn(inOrder,postOrder,start,itr-1,post);
  node->right = treeConstructPostAndIn(inOrder, postOrder,itr+1,end,post);

  return node;
}

void displayPost(TreeNode *root)
{
  if(root == NULL)
  {
    return;
  }
  displayPost(root->left);
  displayPost(root->right);
  printf("Node:%d\n",root->val);
}



int main()
{
  int *inOrder = (int *)calloc(5,sizeof(*inOrder));
  int *preOrder = (int *)calloc(5,sizeof(*inOrder));

  for(size_t itr = 0; itr < 5; ++itr)
  {
    scanf("%d%d",inOrder+itr,preOrder+itr);
  }
  struct TreeNode *node;
  node = treeConstruct(inOrder,preOrder,0,4);
  printf("\n********* Post Order Traversal of the const tree *********\n");
  displayPost(node);
  return EXIT_SUCCESS;
}
