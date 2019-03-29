#include "listLib.h"
// #include "sortLL.h"
// #include "mergeSortLL.h"

int main(void)
{
  unsigned int choice;
  Node *start = NULL, *node = NULL;
  uint32_t pos;
  //int d1, d2;
  int data;
  do
  {
    printf("\n================== ENTER CHOICE ==================\n\
    1. Create\n\
    2. Add at beg\n\
    3. add at last\n\
    4. Add at pos\n\
    5. Delete key\n\
    6. Delete at Pos\n\
    7. Delete List\n\
    8. Search a Node with element in the list\n\
    9. Find the mid of List\n\
    11. Find nth NOde from last\n\
    12. Reverse List\n\
    10. displayList\n\
    0. EXIT\n\
    \n==================================================\n");

    printf("CHOICE:\n");
    scanf("%d",&choice);
    switch (choice)
    {
      case 1:
        printf("Enter data:\n");
        scanf("%d",&data);
        node = createNode(data);
        start = node;
        break;
      case 2:
        printf("Enter data:\n");
        scanf("%d",&data);
        start = addAtBeginning(start,data);
        break;
      case 3:
        printf("Enter data:\n");
        scanf("%d",&data);
        start = addAtEnd(start,data);
        break;
      case 4:
        printf("Enter data\n");
        scanf("%d",&data);
        printf("Enter the position\n");
        scanf("%d",&pos);
        start = addAtPosition(start,data,pos);
        break;
      case 5:
        printf("delete Node with key\n");
        puts("Enter key\n");
        scanf("%d",&data);
        start = deleteKey(start,data);
        break;
      case 6:
        printf("Enter node pos <= 0 to be Deleted:\n");
        scanf("%u",&pos);
        start = deleteAtPos(start,pos);
        break;
      case 7:
        start = deleteEntireList(start);
        break;
      case 8:
        printf("Enter the element to be serached:\n");
        scanf("%d",&data);
        node = search(start,data);
        if(node == NULL)
        {
          printf("Element:%d not in list\n",data);
        }
        else
        {
          printf("Element:%d present at Node addr:%p\n",data,node);
        }
        break;
      case 9:
        node = findMid(start);
        printf("data of mid node:%d\n",node->data);
        break;
      case 10:
        displayList(start);
        break;
      case 11:
        printf("enter idx val from to be searched:\n");
        scanf("%d",&data);
        node = findNthNodeFromLast(start,data);
        if(node != NULL)
        {
          printf("data of node:%d addr of node:%p\n",node->data,node);
        }
        break;
      case 12:
        printf("\n============= Reversed LIST ===========\n");
        start = reverse(start);
        displayList(start);
        break;
      case 0:
        return EXIT_SUCCESS;
      default:
        printf("Error in i/p; enter correct option");
        break;
    }
  } while(choice);
}
