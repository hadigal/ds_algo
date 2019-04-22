/*********************************************************
* use inorder and postorder array to construct bTree
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

TreeNode *treeConstruct(int *inOrder, int *postOrder, int start, int end, int *post)
{
  if(start > end)
  {
    return NULL;
  }

  int rootVal = postOrder[*post];
  *post -= 1;

  TreeNode *node = create(rootVal);

  if(start == end)
  {
    return node;
  }

  size_t itr = start;
  for(;itr <= end; ++itr)
  {
    if(inOrder[itr] == rootVal)
    {
      break;
    }
  }

  node->right = treeConstruct(inOrder,postOrder,itr+1,end,post);
  node->left = treeConstruct(inOrder,postOrder,start,itr-1,post);

  return node;
}

void displayPre(TreeNode *root)
{
  if(root == NULL)
  {
    return;
  }
  printf("Node:%d\n",root->val);
  displayPre(root->left);
  displayPre(root->right);
}

int main()
{
  int *inOrder = (int *)calloc(7,sizeof(*inOrder));
  int *postOrder = (int *)calloc(7,sizeof(*inOrder));

  for(size_t itr = 0; itr < 7; ++itr)
  {
    scanf("%d%d",inOrder+itr,postOrder+itr);
  }

  struct TreeNode *node;
  int postItr = 6;
  node = treeConstruct(inOrder,postOrder,0,6,&postItr);
  printf("\n********* Pre Order Traversal of the const tree *********\n");
  displayPre(node);

  free(inOrder);
  free(postOrder);

  return EXIT_SUCCESS;
}
