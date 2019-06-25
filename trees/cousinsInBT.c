/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins. 

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
*/


void push(struct TreeNode **queue,struct TreeNode *val, int *curr)
{
    ++*curr;
    queue[*curr] = val;
    return;
}


struct TreeNode *pop(struct TreeNode **queue,int *tf)
{
    struct TreeNode *node = queue[*tf];
    ++*tf;
    return node;
}

// logic is to use BFS algo to store the parent of each node for next level
// when iterating  at given level check if value of that node is equal to x || y
// store the subsequent parent for that node. Now once the iterating the entire
// level is compeleted check if parent of that x and y are not NULL and not equal
// if yes return true else return false. If both are still NULL continue iterating
bool isCousins(struct TreeNode* root, int x, int y)
{
    if(root == NULL || root->val == x ||  root->val == y)
    {
        return false;
    }

    struct TreeNode **queue = (struct TreeNode **)malloc(1*sizeof(*queue));
    struct TreeNode **pqueue = (struct TreeNode **)malloc(1*sizeof(*pqueue));
    struct TreeNode *node = NULL, *xp = NULL, *yp = NULL;

    int tf = -1;
    int curr = -1;

    int ptf = -1,pcurr = -1,level = 0;
    int prev = 1,next = 0,itr = 0;

    push(queue,root,&curr);
    ++tf;

    while(tf <= curr)
    {
        while(itr < prev)
        {
            node = pop(queue,&tf);

            if(node->val == x)
            {
                xp = pop(pqueue,&ptf);
            }
            else if(node->val == y)
            {
                yp = pop(pqueue,&ptf);
            }
            else
            {
                if(ptf > -1)
                {
                    pop(pqueue,&ptf);
                }
            }


            if(node->left != NULL)
            {
                if(curr > -1)
                {
                    int sz = curr+1;
                    queue = (struct TreeNode **)realloc(queue,sizeof(*queue)*(sz+1));
                }
                push(queue,node->left,&curr);

                if(pcurr > -1)
                {
                    int sz = pcurr+1;
                    pqueue = (struct TreeNode **)realloc(pqueue,sizeof(*pqueue)*(sz+1));
                }

                push(pqueue,node,&pcurr);
                if(ptf == -1)
                {
                    ++ptf;
                }

                ++next;
            }

            if(node->right != NULL)
            {
                if(curr > -1)
                {
                    int sz = curr+1;
                    queue = (struct TreeNode **)realloc(queue,sizeof(*queue)*(sz+1));
                }
                push(queue,node->right,&curr);

                if(pcurr > -1)
                {
                    int sz = pcurr+1;
                    pqueue = (struct TreeNode **)realloc(pqueue,sizeof(*pqueue)*(sz+1));
                }

                push(pqueue,node,&pcurr);
                if(ptf == -1)
                {
                    ++ptf;
                }

                ++next;
            }

            ++itr;
        }

        if((xp != NULL && yp == NULL) || (xp == NULL && yp != NULL))
        {
            free(pqueue);
            free(queue);
            return false;
        }
        else if(xp != NULL && yp != NULL)
        {
            break;
        }

        ++level;
        prev = next;
        itr = 0;
        next = 0;
    }

    free(pqueue);
    free(queue);

    if(xp == yp)
    {
        return false;
    }
    else
    {
        return true;
    }
}
