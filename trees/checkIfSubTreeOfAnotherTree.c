/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;

// logic is to traverse the the subtree and given tree in pre-order
// if val od 2 node not equal return false
bool checkSubtree(Node *st, Node *t)
{
    if(st == NULL && t == NULL)
    {
        return true;
    }

    if(st == NULL || t == NULL)
    {
        return false;
    }

    if(st->val != t->val)
    {
        return false;
    }

    return (checkSubtree(st->left,t->left) && checkSubtree(st->right,t->right));
}

// recursively check if given subtree of the tree s has equal values as the tree t
// if no then recursively move to the left subtree of s and check with t and then
// move to the right subtree of s. at the end if NULL subtree is reached return false
// O(N*M) time and space

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    if(s == NULL && t != NULL)
    {
        return false;
    }

    if(checkSubtree(s,t) == true)
    {
        return true;
    }

    return (isSubtree(s->left,t) || isSubtree(s->right,t));
}
