/***********************************************************************
Basically return the height of the Tree

104. Maximum Depth of Binary Tree
Easy

1236

47

Favorite

Share
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/******** implemented 2 solutions *************/

// DFS solution where we find the height of left sub tree and compare with the
// height of right subtree and return 1+max val where 1 is for the root node of
// that tree!!

int maxDepth(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int s1 = maxDepth(root->left);
    int s2 = maxDepth(root->right);
    int max;
    if(s1 < s2)
    {
        max = s2;
    }
    else
    {
        max = s1;
    }
    return (1+max);
}


// approach used here BFS --> but due to queue overhead not so optimum
void push(struct TreeNode **queue, int *curr, struct TreeNode *val)
{
    *curr += 1;
    //printf("curr:%d\n",*curr);
    queue[*curr] = val;
    return;
}

struct TreeNode *pop(struct TreeNode **queue,int *topFlg)
{
    struct TreeNode *ret = queue[*topFlg];
    queue[*topFlg] = NULL;
    *topFlg += 1;
    return ret;
}

int maxDepth(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int topFlg = -1;
    int curr = -1;
    struct TreeNode **queue = (struct TreeNode **)calloc(1,sizeof(*queue));
    push(queue,&curr,root);
    ++topFlg;

    struct TreeNode *temp;
    int ret = 0;
    int size = 1;
    while(topFlg <= curr)
    {
        ++ret;
        for(size_t itr = 0, lim = (size-topFlg); itr < lim; ++itr)
        {
            temp = pop(queue,&topFlg);
            if(temp->left != NULL)
            {
                ++size;
                queue = (struct TreeNode **)realloc(queue,sizeof(*queue)*(size));
                push(queue,&curr,temp->left);
            }

            if(temp->right != NULL)
            {
                ++size;
                queue = (struct TreeNode **)realloc(queue,sizeof(*queue)*(size));
                push(queue,&curr,temp->right);
            }
        }
    }
    free(queue);
    return ret;
}
