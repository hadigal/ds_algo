#include "circularList.h"

int main(void)
{
  unsigned int choice;
  Node *last = NULL, *node = NULL;
  int d1, count;
  int data,pos;
  do
  {
    printf("\n================== ENTER CHOICE ==================\n");
    printf("1. Create\n");
    printf("2. Add at beg\n");
    printf("3. add at last\n");
    printf("4. Add At Position\n");
    printf("5. Delete Node\n");
    printf("6. displayList\n");
    printf("7. Print Node Count\n");
    printf("0. EXIT\n");
    printf("\n==================================================\n");

    printf("CHOICE:\n");
    scanf("%d",&choice);
    switch (choice)
    {
      case 1:
        printf("Enter data:\n");
        scanf("%d",&data);
        last = create(data);
        last->next = node;
        break;
      case 2:
        printf("Enter data:\n");
        scanf("%d",&data);
        last = addAtBeginning(last,data);
        break;
      case 3:
        printf("Enter data:\n");
        scanf("%d",&data);
        last = addAtEnd(last,data);
        break;
        break;
      case 5:
        printf("Enter data for node to be deleted:\n");
        scanf("%d",&data);
        last = delete(last,data);
        break;
      case 4:
        printf("Enter data\n");
        scanf("%d",&data);
        printf("Enter the position\n");
        scanf("%d",&pos);
        last = addAtPos(last,data,pos);
        break;
      case 6:
        display(last);
        break;
      case 7:
        count = getNodeCount(last);
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
