#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX 5

typedef struct Node
{
  float val;
  struct Node *next;
}Node;

typedef struct Queue
{
  Node *head;
  Node *tail;
  int size;
  int curr;
}Queue;

Queue *queueObj = NULL;

Queue *createQueueObj(int size)
{
  Queue *obj = (Queue *)calloc(1,sizeof(*obj));
  obj->head = NULL;
  obj->tail = NULL;
  obj->size = size;
  obj->curr = 0;

  return obj;
}

Node *createNode(float val)
{
  Node *node = (Node *)calloc(1,sizeof(*node));
  node->val = val;
  node->next = NULL;

  return node;
}

bool isEmpty(Queue **obj)
{

  if((*obj)->curr == 0 && (*obj)->head == NULL)
  {
    return true;
  }

  return false;
}

bool isFull(Queue **obj)
{
  if((*obj)->curr == (*obj)->size)
  {
    return true;
  }
  return false;
}

void dequeue(Queue **obj)
{
  if(isEmpty(obj) == true)
  {
    return;
  }

  Node *del = (*obj)->head;
  (*obj)->head = del->next;

  (*obj)->curr -= 1;
  free(del);
  return;
}

void enqueue(Queue **obj, float val)
{
  Node *node = createNode(val);

  if(isEmpty(obj) == true)
  {
    (*obj)->head = node;
    (*obj)->tail = node;
    (*obj)->curr += 1;
    return;
  }

  if(isFull(obj) == true)
  {
    dequeue(obj);
  }

  (*obj)->tail->next = node;
  (*obj)->tail = node;
  (*obj)->curr += 1;

  return;
}

float avg(Queue *obj)
{
  Node *head = obj->head;
  int itr = 0;
  float ret;

  while(head != NULL && itr < obj->curr)
  {
    ret += head->val;
    head = head->next;
    ++itr;
  }

  //printf("itr:%d\nobj->curr:%d\n",itr,obj->curr);
  return (ret/obj->curr);
}

void print(Queue *obj)
{
  Node *itr = obj->head;

  while(itr != NULL)
  {
    printf("node:%f\n",itr->val);
    itr = itr->next;
  }
}

float getMovingAvg(float val)
{
  if(queueObj == NULL)
  {
    queueObj = createQueueObj(MAX);
  }

  enqueue(&queueObj,val);
  //print(queueObj);

  return avg(queueObj);
}

int main(void)
{
  float data[11] = {1.0,1.1,2.0,2.1,3,4.0,4.5,5.9,9.8,34.4,4.5};

  int itr = 0;

  while(itr < 11)
  {
    printf("avg ret:%f\n",getMovingAvg(data[itr++]));
  }

  return 0;
}
