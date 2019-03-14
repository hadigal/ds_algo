#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
}Node;

Node *insert(int data)
{
  Node *node = (Node *)calloc(1,sizeof(*node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// left->root->right
void printInOrder(Node *node)
{
  if(node == NULL)
  {
    return;
  }

  printInOrder(node->left);
  printf("data:%d\n",node->data);
  printInOrder(node->right);
}


// root->left->right
void printPreOrder(Node *node)
{
  if(node == NULL)
  {
    return;
  }
  printf("data:%d\n",node->data);
  printPreOrder(node->left);
  printPreOrder(node->right);
}

// left->right->root
void printPostOrder(Node *node)
{
  if(node == NULL)
  {
    return;
  }
  printPostOrder(node->left);
  printPostOrder(node->right);
  printf("data:%d\n",node->data);
}

int main(void)
{
  int val;
  printf("\n******* Enter Data for Tree *******\n");
  scanf("%d",&val);
  Node *root = insert(val);
  scanf("%d",&val);
  root->left = insert(val);
  scanf("%d",&val);
  root->left->left = insert(val);
  scanf("%d",&val);
  root->left->right = insert(val);
  scanf("%d",&val);
  root->right = insert(val);
  printf("\n******* In Order Traversal *********\n");
  printInOrder(root);

  printf("\n******* Pre Order Traversal *********\n");
  printPreOrder(root);

  printf("\n******* Post Order Traversal *********\n");
  printPostOrder(root);
  return EXIT_SUCCESS;
}
