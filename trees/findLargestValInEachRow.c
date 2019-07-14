/*
You need to find the largest value in each row of a binary tree.

Example:
Input:

          1
         / \
        3   2
       / \   \
      5   3   9

Output: [1, 3, 9]

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeNode Node;

void push(Node ***queue, int *curr, Node *val)
{
    if(*curr > -1)
    {
        int sz = *curr +1;
        *queue = (Node **)realloc(*queue,sizeof(Node *)*(sz+1));
    }

    ++*curr;
    queue[0][*curr] = val;
    return;
}

Node *pop(Node **queue,int *tf)
{
    Node *node = queue[*tf];
    ++*tf;
    return node;
}

int* largestValues(struct TreeNode* root, int* retSize)
{
    if(root == NULL)
    {
        *retSize = 0;
        return NULL;
    }

    int level = 0;
    int *ret = (int *)malloc(1*sizeof(*ret));
    Node **queue = (Node **)malloc(1*sizeof(*queue));
    Node *node = NULL;
    int tf = -1, curr = -1, prev = 1, itr = 0, next = 0, max = root->val;
    push(&queue,&curr,root);
    ++tf;

    while(tf <= curr)
    {
        while(itr < prev)
        {
            node = pop(queue,&tf);

            if(itr == 0)
            {
                max = node->val;
            }
            else
            {
                max = (node->val > max)?node->val:max;
            }

            if(node->left != NULL)
            {
                push(&queue,&curr,node->left);
                ++next;
            }

            if(node->right != NULL)
            {
                push(&queue,&curr,node->right);
                ++next;
            }

            ++itr;
        }

        if(next > 0)
        {
            prev = next;
            itr = 0;
            next = 0;
            ret[level] = max;
            max = 0;

            ++level;
            ret = (int *)realloc(ret,sizeof(*ret)*(level+1));
        }
    }

    ret[level] = max;
    *retSize = level+1;
    free(queue);
    return ret;
}
