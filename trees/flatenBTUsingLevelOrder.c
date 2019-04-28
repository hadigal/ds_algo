/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void enqueue(struct TreeNode **queue,int *curr, struct TreeNode *val)
{
    *curr += 1;
    queue[*curr] = val;
    return;
}

struct TreeNode *dequeue(struct TreeNode **queue,int *topFlg)
{
    struct TreeNode *node = queue[*topFlg];
    *topFlg += 1;
    return node;
}

void flatten(struct TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    int size;
    struct TreeNode **queue1 = (struct TreeNode **)malloc(1*sizeof(*queue1));
    struct TreeNode **queue2 = (struct TreeNode **)malloc(1*sizeof(*queue2));
    int topFlg1 = -1, curr1 = -1;
    int topFlg2 = -1, curr2 = -1;

    enqueue(queue1,&curr1,root);
    ++topFlg1;
    enqueue(queue2,&curr2,root);
    ++topFlg2;

    struct TreeNode *node = NULL;

    while(topFlg1 <= curr1)
    {
        node = dequeue(queue1,&topFlg1);

        if(node->left != NULL)
        {
            size = curr1+1;
            queue1 = (struct TreeNode **)realloc(queue1,sizeof(queue1)*(size+1));
            queue2 = (struct TreeNode **)realloc(queue2,sizeof(queue2)*(size+1));
            enqueue(queue1,&curr1,node->left);
            enqueue(queue2,&curr2,node->left);
        }

        if(node->right != NULL)
        {
            size = curr1+1;
            queue1 = (struct TreeNode **)realloc(queue1,sizeof(queue1)*(size+1));
            queue2 = (struct TreeNode **)realloc(queue2,sizeof(queue2)*(size+1));
            enqueue(queue1,&curr1,node->right);
            enqueue(queue2,&curr2,node->right);
        }
    }

    struct TreeNode *rootItr = root;

    while(topFlg2 <= curr2 && rootItr != NULL)
    {
        node = dequeue(queue2,&topFlg2);
        rootItr->right = node;
        rootItr->left = NULL;
        rootItr = rootItr->right;
    }

    free(queue1);
    free(queue2);
}
