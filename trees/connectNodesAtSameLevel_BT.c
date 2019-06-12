/*
Given a binary tree, connect the nodes that are at same level.
Structure of the given Binary Tree node is like following.

struct Node
{
      int data;
      Node* left;
      Node* right;
      Node* nextRight;
}
Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
       10                          10 ------> NULL
      / \                       /      \
     3   5       =>            3 ------> 5 --------> NULL
    / \     \               /  \         \
   4   1   2               4 --> 1 -----> 2 -------> NULL
*/

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes

// helper function to add to queue
void push(Node ***queue,int *curr, Node *val)
{
    if(*curr > -1)
    {
        int sz = *curr + 1;
        queue[0] = (Node **)realloc(queue[0],sizeof(Node *)*(sz+1));
    }

    *curr += 1;
    queue[0][*curr] = val;
    return;
}

//helper function to pop from queue
Node *pop(Node **queue, int *tf)
{
    Node *node = queue[*tf];
    *tf += 1;
    return node;
}

// used BFS approach. Here iterated through every level of BT and kept track of
// prev visited node. Used the prev ptr to mark the prev->nextRight to currNode
void connect(Node *root)
{
   // Your Code Here
   if(root == NULL)
   {
       return;
   }

   //Node ***arr = (Node ***)malloc(1*sizeof(*arr));

   // counters to # nodes at each level
   int currC = 0;
   int newC = 0;
   int prevC = 1;

   // queue to store the nodes at each level
   Node **queue = (Node **)malloc(1*sizeof(*queue));
   int tf = -1;
   int curr = -1;

   // to store the node poped from queue
   Node *node = NULL;
   // to store the prev visited node at that level init to NULL
   Node *prev = NULL;

   push(&queue,&curr,root);
   tf += 1;

   while(tf <= curr)
   {
       while(currC < prevC)
       {
           node = pop(queue,&tf);

           // check if there is any prev node that was already visited
           if(prev != NULL)
           {
              // if yes point the nextRight ptr to curr node;
              // and store curr node at prev
               prev->nextRight = node;
               prev = node;
           }
           else if(prev == NULL)
           {
             // if prev was NULL just store the curr node as prev
               prev = node;
           }

           // now check if curr level node count is reach its limit i.e is equal
           // to number of nodes store in queue while pushing
           // if so mark the curr node next right as NULL to indicate end of nodes
           // at the level
           if(currC == prevC-1)
           {
               node->nextRight = NULL;
               prev = NULL;
           }

           // logic to push right and left child to curr node;
           // also inc the count of nodes with respect curr level
           if(node->left != NULL)
           {
               ++newC;
               push(&queue,&curr,node->left);
           }

           if(node->right != NULL)
           {
               ++newC;
               push(&queue,&curr,node->right);
           }

           ++currC;
       }

       if(newC != 0)
       {
           prevC = newC;
           newC = 0;
           currC = 0;
       }
   }

   free(queue);
}
