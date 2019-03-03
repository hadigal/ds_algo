#include "listLib.h"
//#include "sortLL.h"
#include "mergeSortLL.h"

int main(void)
{
  unsigned int choice;
  Node *start = NULL, *node = NULL;
  int d1, d2;
  int data,pos;
  do
  {
    printf("\n================== ENTER CHOICE ==================\n");
    printf("1. Create\n");
    printf("2. Add at beg\n");
    printf("3. add at last\n");
    printf("4. add in between\n");
    printf("5. add before\n");
    printf("6. add after\n");
    printf("7. Delete Node\n");
    printf("8. Add At Position\n");
    printf("9. Sort List\n");
    printf("10. displayList\n");
    printf("0. EXIT\n");
    printf("\n==================================================\n");

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
        printf("Enter data:\n");
        scanf("%d",&data);
        printf("N1 data:\n");
        scanf("%d",&d1);
        printf("N2 data:\n");
        scanf("%d",&d2);
        start = addInBetweenNodes(start,d1,d2,data);
        break;
      case 5:
        printf("Enter data:\n");
        scanf("%d",&data);
        printf("N1 data:\n");
        scanf("%d",&d1);
        start = addBeforeNode(start,data,d1);
        break;
      case 6:
        printf("Enter data:\n");
        scanf("%d",&data);
        printf("N1 data:\n");
        scanf("%d",&d1);
        start = addAfterNode(start,data,d1);
        break;
      case 7:
        printf("Enter data for node to be deleted:\n");
        scanf("%d",&data);
        start = deleteNode(start,data);
        break;
      case 8:
        printf("Enter data\n");
        scanf("%d",&data);
        printf("Enter the position\n");
        scanf("%d",&pos);
        start = addAtPosition(start,data,pos);
        break;
      case 9:
        //start = sortList(start);
        mergeSort(&start);
        printf("here\n");
        break;
      case 10:
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
