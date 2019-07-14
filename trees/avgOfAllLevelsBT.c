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

static inline void push(Node ***queue, int *curr, Node *val)
{
    if(*curr > -1)
    {
        int sz = *curr + 1;
        *queue = (Node **)realloc(*queue,sizeof(Node *)*(sz+1));
    }
    *curr += 1;
    queue[0][*curr] = val;
}

static inline Node *pop(Node **queue,int *tf)
{
    Node *node = queue[*tf];
    *tf += 1;
    return node;
}

int height(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return (1 + ((lh > rh)?lh:rh));
}

double* averageOfLevels(struct TreeNode* root, int* retSize)
{
    if(root == NULL)
    {
        *retSize = 0;
        return NULL;
    }

    Node **queue = (Node **)malloc(1*sizeof(*queue));
    Node *node = NULL;
    int ht = height(root);

    double *ret = (double *)malloc(ht*sizeof(*ret));
    double sum = 0.0;
    int tf = -1, curr = -1, prev = 1, next = 0, itr = 0, level = 0;
    ret[level] = (double)((double)(root->val)/((double)prev));

    push(&queue,&curr,root);
    ++tf;

    while(tf <= curr)
    {
        while(itr < prev)
        {
            node = pop(queue,&tf);
            if(node->left != NULL)
            {
                sum += node->left->val;
                push(&queue,&curr,node->left);
                ++next;
            }

            if(node->right != NULL)
            {
                sum += node->right->val;
                push(&queue,&curr,node->right);
                ++next;
            }

            ++itr;
        }

        if(next > 0)
        {
            ++level;
            //ret = (double *)realloc(ret,sizeof(*ret)*(level+1));
            ret[level] = sum/((double)next);

            prev = next;
            itr = 0;
            next = 0;
            sum = 0.0;
        }
    }

    *retSize = level + 1;
    free(queue);
    return ret;
}
