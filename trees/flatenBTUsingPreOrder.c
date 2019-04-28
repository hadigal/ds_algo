/********************* LC 114 **************************
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

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
********************************************************/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 // optimized solution using no extra time and space using post-order traversal
 // the trick is use of a dummy node which will hold the updated right tree which
 // is formed by append the root->right with the rightmost nodes!
 void dfsHelper(struct TreeNode *root, struct TreeNode **next)
 {
     if(root == NULL)
     {
         return;
     }

     dfsHelper(root->right,next);
     dfsHelper(root->left,next);

     root->right = *next;
     root->left = NULL;

     *next = root;
 }

 void flatten(struct TreeNode* root)
 {
     if(root == NULL)
     {
         return;
     }
     struct TreeNode *next = NULL;
     dfsHelper(root,&next);
 }


// Uses preorder and extra N time and space to flaten the tree using queue
void enqueue(struct TreeNode **queue,int **curr, struct TreeNode *val)
{
    **curr += 1;
    queue[**curr] = val;
    return;
}

struct TreeNode *dequeue(struct TreeNode **queue,int *topFlg)
{
    struct TreeNode *node = queue[*topFlg];
    *topFlg += 1;
    return node;
}

void dfsHelper(struct TreeNode *root, struct TreeNode ***queue,int *curr)
{
    if(root == NULL)
    {
        return;
    }

    struct TreeNode *node = root;
    if(*curr > -1)
    {
        int size = *curr+1;
        *queue = (struct TreeNode **)realloc(*queue,sizeof(queue[0])*(size+1));
    }
    enqueue(*queue,&curr,node);
    dfsHelper(root->left,queue,curr);
    dfsHelper(root->right,queue,curr);
}


void flatten(struct TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    struct TreeNode **queue = (struct TreeNode **)malloc(1*sizeof(*queue));
    int topFlg = 0, curr = -1;
    dfsHelper(root,&queue,&curr);

    struct TreeNode *rootItr = NULL, *node = NULL;

    while(topFlg <= curr)
    {
        node = dequeue(queue,&topFlg);
        if(rootItr == NULL)
        {
            rootItr = node;
        }
        else
        {
            rootItr->right = node;
            rootItr->left = NULL;
            rootItr = rootItr->right;
        }
    }

    free(queue);
}
