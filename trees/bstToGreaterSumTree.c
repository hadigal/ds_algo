/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

// recursive solution using ptr to store sum of prev node
// also using to reverse version of inOrder traversal where we first iterate the
// right->root->left
// This is memory and time efficient O(n) time and O(1) memory

// iterative solution using 3 stacks;
// not so memory efficient also time complexity => O(3n)
static inline TreeNode *pop(TreeNode **stack, int *topFlg)
{
    TreeNode *ret = stack[*topFlg];
    *topFlg -= 1;

    return ret;
}

static inline void push(TreeNode **stack, int *topFlg, TreeNode *val)
{
    ++*topFlg;
    stack[*topFlg] = val;
}

struct TreeNode* bstToGst(struct TreeNode* root)
{
    if(root == NULL)
    {
        return root;
    }

    TreeNode **stack = (TreeNode **)malloc(1*sizeof(*stack));
    TreeNode **s2 = NULL, **s3 = NULL;
    int tf1 = -1;
    int tf2 = -1;

    //push(stack,&tf1,root);
    TreeNode *itr = root;

    while(itr != NULL || tf1 > -1)
    {
        while(itr != NULL)
        {
            if(tf1 > -1)
            {
                int sz = tf1 + 1;
                stack = (TreeNode **)realloc(stack,sizeof(*stack)*(sz+1));
            }
            push(stack,&tf1,itr);
            itr = itr->left;
        }

        itr = pop(stack,&tf1);
        if(tf2 == -1)
        {
            s2 = (TreeNode **)malloc(1*sizeof(*s2));
        }
        else
        {
            int tmp = tf2 + 1;
            s2 = (TreeNode **)realloc(s2,sizeof(*s2)*(tmp+1));
        }
        push(s2,&tf2,itr);
        itr = itr->right;
    }
    free(stack);

    tf1 = -1;
    s3 = (TreeNode **)malloc((tf2+1)*sizeof(*s3));
    int prev = 0;
    for(int itr = tf2; itr >= 0; --itr)
    {
        TreeNode *node = pop(s2,&tf2);
        node->val += prev;
        prev = node->val;

        push(s3,&tf1,node);
    }

    free(s2);
    free(s3);
    return root;
}
