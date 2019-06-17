/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
in the tree.

According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q as the lowest
node in T that has both p and q as descendants (where we allow a node to be a
  descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]




Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of
itself according to the LCA definition.

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;


// O(N) time and O(N) Space
// logic is to check if the given val1 and val2 is equal to root->val; if yes
// set the ptr to n1Flg / n2Flg to true and return root else move to left subtree first
// and then right subtree. If the NULL is reached
// return NULL if both leftLCA, rightLCA nodes are found return root else check if
// leftLCA is NULL return rtLCA else return left LCA.
Node *findLCA(Node *root, int val1, int val2, bool *p1, bool *p2)
{
    if(root == NULL)
    {
        return NULL;
    }

    // check if val1 and val2 are equal to root->val
    if(root->val == val1)
    {
        *p1 = true;
        return root;
    }
    else if(root->val == val2)
    {
        *p2 = true;
        return root;
    }

    // first move left subtree and then right subtree
    Node *ltLCA = findLCA(root->left,val1,val2,p1,p2);
    Node *rtLCA = findLCA(root->right,val1,val2,p1,p2);

    if(ltLCA != NULL && rtLCA != NULL)
    {
        return root;
    }

    // if leftLCA  is NULL return rightLCA else leftLCA
    Node *ret = (ltLCA != NULL)?ltLCA:rtLCA;

    return ret;
}

// this for the scenario where the lca node is one of the node values; this will be Used
// to find other node val is present in the tree of that LCA node as root!!
bool findNode(Node *root, int val)
{
    if(root == NULL)
    {
        return false;
    }

    if(root->val == val)
    {
        return true;
    }

    return (findNode(root->left,val) || findNode(root->right,val));
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if(root == NULL || p == NULL || q == NULL)
    {
        return NULL;
    }


    int val1 = p->val;
    int val2 = q->val;

    bool p1 = false;
    bool p2 = false;

    Node *lca = findLCA(root,val1,val2,&p1,&p2);

    if(p1 == true && p2 == true)
    {
        return lca;
    }
    else if((p1 == true && findNode(lca,val2) == true) || (p2 == true && findNode(lca,val1)))
    {
        return lca;
    }
    else
    {
        return NULL;
    }
}
