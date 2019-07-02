/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.



Example:



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false


Note:

next() and hasNext() should run in average O(1) time and uses O(h) memory,
where h is the height of the tree. You may assume that next() call will always
be valid, that is, there will be at least a next smallest number in the BST
when next() is called.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct
{
    struct TreeNode *root;
    int *inOrder;
    int count;
    int currCount;
} BSTIterator;


void getInOrder(struct TreeNode *root,int **arr,int *count)
{
    if(root == NULL)
    {
        return;
    }

    getInOrder(root->left,arr,count);

    if(*count > 0)
    {
        int sz = *count + 1;
        *arr = (int *)realloc(*arr,sizeof(int)*sz);
    }
    arr[0][*count] = root->val;
    ++*count;
    getInOrder(root->right,arr,count);
}


BSTIterator* bSTIteratorCreate(struct TreeNode* root)
{
    BSTIterator *obj = (BSTIterator *)malloc(1*sizeof(*obj));
    obj->inOrder = (int *)malloc(1*sizeof(int));
    obj->count  = 0;
    getInOrder(root,&(obj->inOrder),&(obj->count));
    obj->currCount  = 0;
    return obj;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator* obj)
{
//     if(bSTIteratorHasNext(obj) == false)
//     {
//         return ((obj->inOrder)[obj->count - 1]);
//     }


    //int ret = (obj->inOrder)[obj->currCount++];
    //obj->currCount += 1;

    //return ret;

    return ((obj->inOrder)[obj->currCount++]);
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator* obj)
{
    if(obj->currCount >= obj->count)
    {
        return false;
    }

    return true;
}

void bSTIteratorFree(BSTIterator* obj)
{
    if(obj != NULL)
    {
        free(obj->inOrder);
        free(obj);
    }

    return;
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/
