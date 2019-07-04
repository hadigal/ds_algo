/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


 // Logic is to create a list add elements at top of list while iterating tree
 // using preorder traversal update sum at each iteration by sum - root->val.
 // When we reach leaf node check if sum is equal to root->val if yes then add the
 // elements added to list in reverse order to the 2d array ret and return; if not
 // then just return. Once we have finished iterating both left and right leaf nodes
 // decrement the node counter count so that we do not repeat the node value in our next
 // iteration, also remove the node from head of the list if next node in the list
 // is not NULL. complexity O(N*h*path)

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

typedef struct LL
{
    Node *head;
}LL;

static Node *create(int val)
{
    Node *node = (Node *)malloc(1*sizeof(*node));
    node->val = val;
    node->next = NULL;

    return node;
}

void freeLL(Node *head)
{
    if(head == NULL)
    {
        return;
    }

    Node *itr = head;
    Node *node;

    while(itr != NULL)
    {
        node = itr;
        itr = node->next;
        free(node);
    }

    return;
}

void helper(struct TreeNode *root, LL **obj, int ***ret, int *len, int *count, int **col, int sum)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        if(sum == root->val)
        {
            int sz = *count + 1;
            Node *itr = (*obj)->head;
            int tmp = *count - 1;

            if(*len > 0)
            {
                *ret = (int **)realloc(*ret,sizeof(int *)*(*len+1));
                *col = (int *)realloc(*col,sizeof(int)*(*len+1));
            }

            col[0][*len] = sz;
            ret[0][*len] = (int *)malloc(sz*sizeof(int));

            while(itr != NULL && tmp >= 0)
            {
                ret[0][*len][tmp--] = itr->val;
                itr = itr->next;
            }

            ret[0][*len][*count] = root->val;
            *len += 1;

            return;
        }
        else
        {
            return;
        }
    }
    else
    {
        Node *node = create(root->val);

        if((*obj)->head == NULL)
        {
            (*obj)->head = node;
            //(*obj)->tail = node;
        }
        else
        {
            node->next = (*obj)->head;
            (*obj)->head = node;
        }

        ++*count;
    }

    helper(root->left,obj,ret,len,count,col,(sum - root->val));
    helper(root->right,obj,ret,len,count,col,(sum - root->val));

    if((*obj)->head != NULL)
    {
        Node *tmp = (*obj)->head;
        if(tmp->next != NULL)
        {
            (*obj)->head = tmp->next;
            free(tmp);
        }
    }

    if(*count > 1)
    {
        --*count;
    }
}

int** pathSum(struct TreeNode* root, int sum, int* row, int** retColSize)
{
    if(root == NULL)
    {
        *row = 0;
        *retColSize = NULL;
        return NULL;
    }

    int **ret = (int **)malloc(1*sizeof(*ret));
    int len = 0;
    int count = 0;

    LL *obj = (LL *)malloc(1*sizeof(*obj));
    *retColSize = (int *)malloc(1*sizeof(*ret));

    obj->head = NULL;
    //obj->tail = NULL;

    helper(root,&obj,&ret,&len,&count,retColSize,sum);

    if(len == 0)
    {
        free(ret);
        ret = NULL;
        free(*retColSize);
        *retColSize = NULL;
    }

    //freeLL(obj->head);
    free(obj);
    *row = len;
    return ret;
}
