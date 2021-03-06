#include "doublyListLib.h"

int main(void)
{
  unsigned int choice;
  Node *start = NULL, *node = NULL;
  int d1, count;
  int data,pos;
  do
  {
    printf("\n================== ENTER CHOICE ==================\n");
    printf("1. Create\n");
    printf("2. Add at beg\n");
    printf("3. add at last\n");
    printf("4. add before\n");
    printf("5. add after\n");
    printf("6. Delete Node\n");
    printf("7. Add At Position\n");
    printf("8. displayList\n");
    printf("9. Print Node Count\n");
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
        start = addBeforeNode(start,data,d1);
        break;
      case 5:
        printf("Enter data:\n");
        scanf("%d",&data);
        printf("N1 data:\n");
        scanf("%d",&d1);
        start = addAfterNode(start,data,d1);
        break;
      case 6:
        printf("Enter data for node to be deleted:\n");
        scanf("%d",&data);
        start = deleteNode(start,data);
        break;
      case 7:
        printf("Enter data\n");
        scanf("%d",&data);
        printf("Enter the position\n");
        scanf("%d",&pos);
        start = addAtPosition(start,data,pos);
        break;
      case 8:
        displayList(start);
        break;
      case 9:
        count = getNodeCount(start);
        printf("Total node in list:%d\n",count);
        break;
      case 0:
        return EXIT_SUCCESS;
      default:
        printf("Error in i/p; enter correct option");
        break;
    }
  } while(choice);
}
