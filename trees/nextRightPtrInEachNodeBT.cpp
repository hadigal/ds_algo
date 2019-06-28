/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:

    static inline void push(Node ***queue, int *curr, Node *val)
    {
        if(*curr > -1)
        {
            int sz = *curr +1;
            *queue = (Node **)realloc(*queue,sizeof(Node *)*(sz+1));
        }

        ++*curr;
        queue[0][*curr] = val;

        return;
    }

    static inline Node *pop(Node **queue, int *tf)
    {
        Node *node = queue[*tf];
        ++*tf;
        return node;
    }


    Node* connect(Node* root)
    {
        if(root == NULL)
        {
            return root;
        }

        Node **queue = (Node **)malloc(1*sizeof(*queue));
        Node *node = NULL, *prevNode = NULL;
        int tf = -1, curr = -1;
        push(&queue,&curr,root);
        ++tf;
        int prev = 1, next = 0, itr = 0;

        while(tf <= curr)
        {
            while(itr < prev)
            {
                node = pop(queue,&tf);
                if(itr == 0)
                {
                    prevNode = node;
                }
                else
                {
                    prevNode->next = node;
                    prevNode = node;
                }

                if(itr == (prev-1))
                {
                    node->next = NULL;
                }

                if(node->left != NULL)
                {
                    push(&queue,&curr,node->left);
                    ++next;
                }

                if(node->right != NULL)
                {
                    push(&queue,&curr,node->right);
                    ++next;
                }

                ++itr;
            }

            if(next > 0)
            {
                prevNode = NULL;
                prev = next;
                itr = 0;
                next = 0;
            }
        }

        free(queue);
        return root;
    }
};
