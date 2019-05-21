#ifndef __BST_H__
#define __BST_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
}TreeNode;

TreeNode *createNode(int val);

TreeNode *insert(TreeNode *root, int key);

TreeNode *delete(TreeNode *root, int key);

TreeNode *search(TreeNode *root, int key);

void preOrder(TreeNode *root);

void postOrder(TreeNode *root);

void inOrder(TreeNode *root);

TreeNode *min(TreeNode *root);

TreeNode *max(TreeNode *root);

#endif
