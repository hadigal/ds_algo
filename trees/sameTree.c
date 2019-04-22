/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// used post order traversal approach
// first iterate all the nodes of each tree check if all the child nodes of left sub tree
// are equal to right subtree of both the trees; then check if roots are equal of
// both the nodes!!
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(p == NULL && q == NULL)
    {
        return true;
    }
    else if((p == NULL && q != NULL) || (p != NULL && q == NULL))
    {
        return false;
    }

    bool r1 = isSameTree(p->left,q->left);
    bool r2 = isSameTree(p->right,q->right);

    if(p->val == q->val && r1 == true && r2 == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
