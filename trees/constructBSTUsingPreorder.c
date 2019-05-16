/******************* lc: 1008 ****************************
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.
left has a value < node.val, and any descendant of node.right has a value > node.val.
Also recall that a preorder traversal displays the value of the node first,
then traverses node.left, then traverses node.right.)


Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Note:

1 <= preorder.length <= 100
The values of preorder are distinct.
***************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;

TreeNode *create(int val)
{
    TreeNode *node = (TreeNode *)malloc(1*sizeof(*node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

TreeNode *createBST(int *arr, int lIdx, int rIdx)
{
    //if(lIdx > rIdx || rIdx < lIdx)
    if(lIdx == rIdx)
    {
        return NULL;
    }

    int rootVal = arr[0];
    TreeNode *tmpRoot = create(rootVal);

    if(lIdx == rIdx-1)
    {
        return tmpRoot;
    }

    int *left = (int *)malloc(1*sizeof(*left));
    int *right = (int *)malloc(1*sizeof(*right));

    int leftItr = 0;
    int rightItr = 0;

    for(size_t itr = lIdx+1; itr <= rIdx-1; ++itr)
    {
        if(arr[itr] < rootVal)
        {
            if(leftItr > 0)
            {
                left = (int *)realloc(left,sizeof(*left)*(leftItr+1));
            }
            left[leftItr++] = arr[itr];
        }
        else if(arr[itr] > rootVal)
        {
            if(rightItr > 0)
            {
                right = (int *)realloc(right,sizeof(*left)*(rightItr+1));
            }
            right[rightItr++] = arr[itr];
        }
    }

    tmpRoot->left = createBST(left,0,leftItr);
    tmpRoot->right = createBST(right,0,rightItr);

    return tmpRoot;
}

struct TreeNode* bstFromPreorder(int* preorder, int len)
{
    TreeNode *root = NULL;
    if(len == 0)
    {
        return root;
    }

    root = createBST(preorder,0,len);

    return root;
}
