/*
Given two binary trees and imagine that when you put one of them to cover
the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two
nodes overlap, then sum node values up as the new value of the merged node.
Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

Input:
	Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
Output:
Merged tree:
	     3
	    / \
	   4   5
	  / \   \
	 5   4   7


Note: The merging process must start from the root nodes of both trees.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



void dfsHelper(struct TreeNode *r1, struct TreeNode *r2, struct TreeNode *prev1, struct TreeNode *prev2)
{
    if((r1 == NULL && r2 == NULL))
    {
        return;
    }
    else if(r1 != NULL && r2 == NULL)
    {
        return;
    }

    // check if node of t1 is NULL if yes check if it is the right or left node of
    // prev t1 node and merge t2 accordingly, if both nodes of prev t1 node is NULL
    // then check if current t2 node is left or right child of prev t2 node and
    // accordingly add the curr t2 to right or left of prev t1 node!
    if(r1 == NULL)
    {
        if(prev1->left == NULL && prev1->right == NULL)
        {
            //printf("here-----\n");
            if(prev2->left == r2)
            {
                prev1->left = r2;
            }
            else
            {
                prev1->right = r2;
            }

        }
        else if(prev1->left != NULL)
        {
            prev1->right = r2;
        }
        else
        {
            prev1->left = r2;
        }

        return;
    }
    else
    {
        r1->val += r2->val;
    }

    dfsHelper(r1->left,r2->left,r1,r2);
    dfsHelper(r1->right,r2->right,r1,r2);
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2)
{
    if(t1 == NULL)
    {
        return t2;
    }
    else if(t2 == NULL)
    {
        return t1;
    }

    dfsHelper(t1,t2,(struct TreeNode *)NULL,(struct TreeNode *)NULL);
    return t1;
}
