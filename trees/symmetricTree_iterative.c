/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;

void push(Node **queue, int *curr, Node *val)
{
    *curr += 1;
    queue[*curr] = val;
    return;
}

Node *pop(Node **queue, int *tf)
{
    Node *ret = queue[*tf];
    *tf += 1;
    return ret;
}

bool isSymmetric(struct TreeNode* root)
{
    if(root == NULL)
    {
        return true;
    }

    Node *queue = (Node **)malloc(2*sizeof(*queue));
    Node *rt,*lf;
    int tf = -1;
    int curr = -1;

    push(queue,&curr,root);
    tf += 1;
    push(queue,&curr,root);


    while(tf <= curr)
    {
        lf = pop(queue,&tf);
        rt = pop(queue,&tf);

        if(lf->val != rt->val)
        {
            free(queue);
            return false;
        }

        if(lf->left != NULL && rt->right != NULL)
        {
            if(curr > -1)
            {
                int sz = curr + 1;
                queue = (Node **)realloc(queue,sizeof(*queue)*(sz+2));
            }
            
            push(queue,&curr,lf->left);
            push(queue,&curr,rt->right);
        }
        else if(lf->left || rt->right)
        {
            free(queue);
            return false;
        }

        if(lf->right != NULL && rt->left != NULL)
        {
            if(curr > -1)
            {
                int sz = curr + 1;
                queue = (Node **)realloc(queue,sizeof(*queue)*(sz+2));
            }
            push(queue,&curr,lf->right);
            push(queue,&curr,rt->left);
        }
        else if(lf->right != NULL || rt->left != NULL)
        {
            free(queue);
            return false;
        }
    }

    free(queue);
    return true;
}
