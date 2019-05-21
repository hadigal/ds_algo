#include "BST.h"

TreeNode *inPost(int *post, int *in, int *pIdx, int lIdx, int rIdx, int len)
{
  if(lIdx > rIdx)
  {
    return NULL;
  }

  int rootVal = post[*pIdx];
  --*pIdx;

  TreeNode *node  = createNode(rootVal);
  if(lIdx == rIdx)
  {
    return node;
  }

  int itr;

  for(itr = lIdx; itr <= rIdx; ++itr)
  {
    if(in[itr] == rootVal)
    {
      break;
    }
  }

  node->right = inPost(post, in, pIdx, itr+1,rIdx,len);
  node->left = inPost(post, in, pIdx, lIdx,itr-1,len);

  return node;
}


int main(void)
{
  int c;
  int in[7] = {1,2,3,4,5,6,7};
  int post[7] = {1,3,2,5,7,6,4};
  int pIdx = 6;
  TreeNode *root = inPost(post, in, &pIdx,0,6,6);

  while(1)
  {
    printf("\n\n");
    printf("1. Search\n");
    printf("2. Insert\n");
    printf("3. Delete\n");
    printf("4. print in order\n");
    printf("5. print pre order\n");
    printf("6. print post order\n");
    printf("7. min\n");
    printf("8. max\n");
    printf("9. exit\n");

    scanf("%d",&c);
    TreeNode *ret;
    int key;
    switch (c)
    {
      case 1:
        printf("enter key:\n");
        scanf("%d",&key);
        ret = search(root,key);
        if(ret == NULL)
        {
          printf("not found\n");
        }
        else
        {
          printf("addr:%p\n",ret);
        }

        break;
      case 2:
        printf("enter key:\n");
        scanf("%d",&key);
        ret = insert(root,key);
        break;
      case 3:
        printf("enter key:\n");
        scanf("%d",&key);
        ret = delete(root,key);
      case 4:
        inOrder(root);
        break;
      case 5:
        preOrder(root);
        break;
      case 6:
        postOrder(root);
        break;
      case 7:
        ret = min(root);
        printf("min[%p]:%d\n",ret,ret->val);
        break;
      case 8:
        ret = max(root);
        printf("max[%p]:%d\n",ret,ret->val);
        break;
      case 9:
        return EXIT_SUCCESS;
      default:
        printf("wrong input\n");
        break;
    }
  }
}
