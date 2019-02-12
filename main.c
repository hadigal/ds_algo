#include "listLib.h"

int main(void)
{
  unsigned int choice;
  Node *start = NULL, *node = NULL;
  int data;
  do
  {
    printf("\n================== ENTER CHOICE ==================\n");
    printf("1. Create\n");
    printf("2. Add at beg\n");
    printf("3. add at last\n");
    printf("4. displayList\n");
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
        printf("----start->next:%p\n",start->next);
        break;
      case 3:
        printf("Enter data:\n");
        scanf("%d",&data);
        start = addAtEnd(start,data);
        break;
      case 4:
        printf(">>>>>>>>>>>> displayList start->next:%p\n",start);
        printf("------------> start->next:%p\n",start->next);
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
