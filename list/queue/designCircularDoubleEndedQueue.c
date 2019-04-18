/*********************************** Leetcode Problem *************************
** SOLVED USING Linked List **
Design your implementation of the circular double-ended queue (deque).

Your implementation should support following operations:

MyCircularDeque(k): Constructor, set the size of the deque to be k.
insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
getRear(): Gets the last item from Deque. If the deque is empty, return -1.
isEmpty(): Checks whether Deque is empty or not.
isFull(): Checks whether Deque is full or not.


Example:

MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
circularDeque.insertLast(1);			// return true
circularDeque.insertLast(2);			// return true
circularDeque.insertFront(3);			// return true
circularDeque.insertFront(4);			// return false, the queue is full
circularDeque.getRear();  			// return 2
circularDeque.isFull();				// return true
circularDeque.deleteLast();			// return true
circularDeque.insertFront(4);			// return true
circularDeque.getFront();			// return 4


Note:

All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Deque library.
*******************************************************************************/
#define NULL ((void *)(0))

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

typedef struct
{
    Node *front;
    Node *rear;
    int currSize;
    uint32_t size;
} MyCircularDeque;

Node *create(int val)
{
    Node *node = (Node *)calloc(1,sizeof(*node));
    node->val = val;
    node->next = NULL;
    return node;
}

void push(MyCircularDeque **queue,int val, int flg)
{
    Node *node;
    Node *rear = (*queue)->rear;
    Node *front = (*queue)->front;

    node = create(val);
    if(front == NULL)
    {
        (*queue)->front = node;
        ((*queue)->front)->next = node;
        (*queue)->rear = node;
        (*queue)->currSize += 1;
        return;
    }

    Node *temp;

    if(flg == 0)
    {
        node->next = front;
        ((*queue)->rear)->next = node;
        (*queue)->front = node;
    }
    else
    {
        node->next = rear->next;
        ((*queue)->rear)->next = node;
        (*queue)->rear = node;
    }
    (*queue)->currSize += 1;
    return;
}

void pop(MyCircularDeque **queue,int flg)
{
    Node *rear = (*queue)->rear;
    Node *front = (*queue)->front;

    Node *temp;
    if(front == rear)
    {
        temp = front;
        free(temp);
        (*queue)->front = NULL;
        (*queue)->front = NULL;
        (*queue)->currSize = 0;
        return;
    }

    if(flg == 0)
    {
        temp = front;
        (*queue)->front = front->next;
        ((*queue)->rear)->next = (*queue)->front;
        free(temp);
    }
    else
    {
        temp = rear;
        Node *itr1 = front;
        Node *itr2 = front;

        while(itr1->next != rear)
        {
            itr1 = itr1->next;
            if(itr2->next != rear)
            {
                itr2 = itr2->next;
                itr1 = itr1->next;
            }
        }

        itr1->next = rear->next;
        (*queue)->rear = itr1;
        free(temp);
    }
    (*queue)->currSize -= 1;
    return;
}

// void print(MyCircularDeque *obj)
// {
//     printf("from front\n");
//     Node *itr = obj->front;
//     while(itr->next != obj->front)
//     {
//         printf("node:%d\n",itr->val);
//         itr = itr->next;
//     }
//     printf("node_last:%d\n",itr->val);
// }

/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque* myCircularDequeCreate(int k)
{
    MyCircularDeque *queue = (MyCircularDeque *)calloc(1,sizeof(*queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->currSize = 0;
    queue->size = k;

    return queue;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj)
{
    if(obj->front == NULL && obj->currSize == 0)
    {
        return true;
    }
    return false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj)
{
    if(obj->currSize == obj->size)
    {
        return true;
    }
    return false;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value)
{
    if(myCircularDequeIsFull(obj) == true)
    {
        return false;
    }
    push(&obj,value,0);
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value)
{
    if(myCircularDequeIsFull(obj) == true)
    {
        return false;
    }
    push(&obj,value,1);
    //print(obj);
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj)
{
    if(myCircularDequeIsEmpty(obj) == true)
    {
        return false;
    }

    pop(&obj,0);
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj)
{
    if(myCircularDequeIsEmpty(obj) == true)
    {
        return false;
    }

    pop(&obj,1);
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj)
{
    if(myCircularDequeIsEmpty(obj) == true)
    {
        return -1;
    }
    Node *front = obj->front;
    int val = front->val;
    return val;
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj)
{
    if(myCircularDequeIsEmpty(obj) == true)
    {
        return -1;
    }

    Node *rear = obj->rear;
    int val = rear->val;
    return val;
}

void myCircularDequeFree(MyCircularDeque* obj)
{
    if(myCircularDequeIsEmpty(obj) == true)
    {
        free(obj);
        return;
    }

    Node *front = obj->front;
    Node *itr = front;
    Node *temp;
    while(itr->next != front)
    {
        temp = itr;
        itr = itr->next;
        free(temp);
    }
    free(itr);
    free(obj);
    return;
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * struct MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 * bool param_3 = myCircularDequeDeleteFront(obj);
 * bool param_4 = myCircularDequeDeleteLast(obj);
 * int param_5 = myCircularDequeGetFront(obj);
 * int param_6 = myCircularDequeGetRear(obj);
 * bool param_7 = myCircularDequeIsEmpty(obj);
 * bool param_8 = myCircularDequeIsFull(obj);
 * myCircularDequeFree(obj);
 */
