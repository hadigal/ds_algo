/************************* LC: 144 ***********************************
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
**********************************************************************/


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

// iterative approach; in this used stack to store the root nodes
// while the stack is not empty start pop the nodes from top of the stack which are all
// root nodes during push operating 1st right then left.
 static inline void push(struct TreeNode **stack, int *topFlg, struct TreeNode *val)
 {
     *topFlg += 1;
     stack[*topFlg] = val;
     return;
 }

 static inline struct TreeNode *pop(struct TreeNode **stack, int *topFlg)
 {
     struct TreeNode *node = stack[*topFlg];
     *topFlg -= 1;
     return node;
 }

 int* preorderTraversal(struct TreeNode* root, int* returnSize)
 {
     int *arr = NULL;
     if(root == NULL)
     {
         *returnSize = 0;
         return arr;
     }

     int count = 0;
     int topFlg = -1, size = 0;
     arr = (int *)malloc((count+1)*sizeof(*arr));
     struct TreeNode **stack = (struct TreeNode **)malloc((size+1)*sizeof(*stack));
     ++size;
     push(stack,&topFlg,root);
     struct TreeNode *node;

     while(topFlg >= 0)
     {
         node = pop(stack,&topFlg);
         if(count > 0)
         {
             arr = (int *)realloc(arr,sizeof(*arr)*(count+1));
         }
         arr[count++] = node->val;

         if(node->right != NULL)
         {
             stack = (struct TreeNode **)realloc(stack,sizeof(*stack)*(size+1));
             ++size;
             push(stack,&topFlg,node->right);
         }

         if(node->left != NULL)
         {
             stack = (struct TreeNode **)realloc(stack,sizeof(*stack)*(size+1));
             ++size;
             push(stack,&topFlg,node->left);
         }
     }

     *returnSize = count;
     free(stack);
     return arr;
 }

// v. trivial recursive approach
void dfsHelper(struct TreeNode *root, int **arr, int *count)
{
    if(root == NULL)
    {
        return;
    }
    if(*count > 0)
    {
        *arr = (int *)realloc(*arr,sizeof(**arr)*(*count+1));
    }
    arr[0][*count] = root->val;
    *count += 1;

    dfsHelper(root->left,arr,count);
    dfsHelper(root->right,arr,count);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *arr = NULL;
    if(root == NULL)
    {
        *returnSize = 0;
        return arr;
    }

    int count = 0;
    arr = (int *)calloc(count+1,sizeof(*arr));

    dfsHelper(root,&arr,&count);

    *returnSize = count;
    return arr;
}
