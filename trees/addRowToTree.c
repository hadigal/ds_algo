/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;

static inline Node *create(int val)
{
    Node *node = (Node *)malloc(1*sizeof(*node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void dfs(Node **root, int val,int level, int d)
{
    if(*root == NULL)
    {
        return;
    }

    if(level == d)
    {

        Node *lch = (*root)->left;
        (*root)->left = create(val);
        (*root)->left->left = lch;

        Node *rch = (*root)->right;
        (*root)->right = create(val);
        (*root)->right->right = rch;

        return;
    }

    dfs(&((*root)->left),val,level+1,d);
    dfs(&((*root)->right),val,level+1,d);

    return;
}


struct TreeNode* addOneRow(struct TreeNode* root, int v, int d)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(d == 1)
    {
        Node *newR = create(v);
        newR->left = root;
        return newR;
    }

    int level = 1;
    dfs(&root,v,level,d-1);

    return root;
}
