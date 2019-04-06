/*
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.
*/

#define NULL ((void *)0)

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

typedef struct
{
    Node *front;
    Node *rear;
    int size;
    int currSize;
} MyCircularQueue;

Node *create(int val)
{
    Node *node = (Node *)calloc(1,sizeof(*node));
    node->val = val;
    node->next = NULL;

    return node;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    Node *head = obj->front;
    Node *tail = obj->rear;

    if(head == NULL && tail == NULL && obj->currSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    if(obj->currSize == obj->size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue *newQ = (MyCircularQueue *)calloc(1,sizeof(*newQ));
    newQ->front = NULL;
    newQ->rear = NULL;

    newQ->size = k;
    newQ->currSize = 0;

    return newQ;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    Node **head = &(obj->front);
    Node **tail = &(obj->rear);
    Node *node;

    if(myCircularQueueIsEmpty(obj) == true)
    {
        node = create(value);
        //node->next = NULL;
        (*head) = node;
        (*tail) = node;
        (*tail)->next = (*head);
        obj->currSize += 1;
        return true;
    }

    if(myCircularQueueIsFull(obj) == true)
    {
        return false;
    }

    node = create(value);
    //(*head) = node;
    Node *tmp = *tail;
    node->next = tmp->next;
    tmp->next = node;
    *tail = node;
    //(*tail)->next = (*head);
    obj->currSize += 1;

    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    if(myCircularQueueIsEmpty(obj) == true)
    {
        return false;
    }

    Node **head = &(obj->front);
    Node **tail = &(obj->rear);
    Node *tmp;

    if(*head == *tail && obj->currSize == 1)
    {
        tmp = *head;
        *head = NULL;
        *tail = NULL;

        obj->currSize = 0;

        free(tmp);
        return true;
    }

    tmp = *head;

    // mark head/front to next element;
    *head = tmp->next;
    (*tail)->next = *head;
    obj->currSize -= 1;

    free(tmp);
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj)
{
    if(myCircularQueueIsEmpty(obj) == true)
    {
        return -1;
    }
    Node *head = obj->front;
    int ret = head->val;

    return ret;
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj)
{
    if(myCircularQueueIsEmpty(obj) == true)
    {
        return -1;
    }
    Node *tail = obj->rear;
    int ret = tail->val;

    return ret;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
    Node **head = &(obj->front);
    Node **tail = &(obj->rear);

    if(myCircularQueueIsEmpty(obj) == true)
    {
        free(obj);
        return;
    }

    Node *tmp;
    Node *itr = *head;

    while(itr != *tail)
    {
        tmp = itr;
        itr = tmp->next;
        free(tmp);
    }
    tmp = *tail;
    free(tmp);
    *head = NULL;
    *tail = NULL;

    free(obj);

    return;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * struct MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 * bool param_2 = myCircularQueueDeQueue(obj);
 * int param_3 = myCircularQueueFront(obj);
 * int param_4 = myCircularQueueRear(obj);
 * bool param_5 = myCircularQueueIsEmpty(obj);
 * bool param_6 = myCircularQueueIsFull(obj);
 * myCircularQueueFree(obj);
 */
