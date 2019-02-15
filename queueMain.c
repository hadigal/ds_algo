#include "queueLib.h"

int main(void)
{
  frontNode = NULL;
  rearNode = NULL;
  fullFlag = -1;
  int choice;
  //scanf("Enter choice:\n");
  int val;

  do
  {
    printf("\n================== ENTER CHOICE ==================\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. PEEK\n");
    printf("4. IS EMPTY\n");
    printf("5. IS FULL\n");
    printf("6. DISPLAY\n");
    printf("0. EXIT\n");
    printf("\n==================================================\n");

    printf("Enter Choice:\n");
    scanf("%d",&choice);


    switch (choice)
    {
      case 1:
        printf("Enter data to be added to the queue:\n");
        scanf("%d",&val);
        insert(val);
        break;
      case 2:
        delete();
        break;
      case 3:
        val = peek();
        if(val == 0)
        {
          printf("queue IS EMPTY\n");
          break;
        }
        printf("Current data at Top of QUEUE:%d\n",val);
        peek();
        break;
      case 4:
        val = isEmpty();
        if(val == 1)
        {
          printf("queue is empty\n");
        }
        else if(val == 0)
        {
          printf("queue is not empty\n");
        }
        break;
      case 5:
        val = isFull();
        if(val == 1)
        {
          printf("queue is FULL\n");
        }
        else if(val == 0)
        {
          printf("queue is not FULL\n");
        }
        break;
      case 6:
          display();
          break;
      case 0:
        return EXIT_SUCCESS;
      default:
        printf("Invalid CHOICE\n");
        break;
    }
  } while(1);
}
