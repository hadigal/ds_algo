/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;

// int kthSmallest(struct TreeNode* root, int k)
// {

// }

static inline void push(Node **stack, int *tf, Node *val)
{
    *tf += 1;
    stack[*tf] = val;
    return;
}

static inline Node *pop(Node **stack, int *tf)
{
    Node *ret = stack[*tf];
    *tf -= 1;
    return ret;
}

int kthSmallest(struct TreeNode* root, int k)
{

    Node **stack = (Node **)malloc(1*sizeof(*stack));
    int tf = -1;
    int count = 0;
    Node *itr = root;

    while(itr != NULL || tf > -1)
    {
        while(itr != NULL)
        {
            if(tf > -1)
            {
                int sz = tf+1;
                stack = (Node **)realloc(stack,sizeof(*stack)*(sz+1));
            }
            push(stack,&tf,itr);
            itr = itr->left;
        }

        itr = pop(stack,&tf);
        ++count;
        if(count == k)
        {
            break;
        }
        itr = itr->right;
    }

    int val = itr->val;
    free(stack);
    return val;
}
