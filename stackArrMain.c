#include "stackLib.h"

int main(void)
{
  unsigned int choice;
  int data, val;
  stackArr = (int *)calloc(MAXSIZE,sizeof(*stackArr));

  do
  {
    printf("\n================== ENTER CHOICE ==================\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
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
        printf("Enter data to be pushed:\n");
        scanf("%d",&data);
        push(data);
        break;
      case 2:
        val = pop();
        printf("POPED data:%d\n",val);
        break;
      case 3:
        val = peek();
        if(val == 0)
        {
          printf("STACK IS EMPTY\n");
          break;
        }
        printf("Current data at Top of stack:%d\n",val);
        peek();
        break;
      case 4:
        val = isEmpty();
        if(val == 1)
        {
          printf("stack is empty\n");
        }
        else if(val == 0)
        {
          printf("stack is not empty\n");
        }
        break;
      case 5:
        val = isFull();
        if(val == 1)
        {
          printf("stack is FULL\n");
        }
        else if(val == 0)
        {
          printf("stack is not NOT\n");
        }
        break;
      case 6:
          displayStack();
          break;
      case 0:
        return EXIT_SUCCESS;
      default:
        printf("Invalid CHOICE\n");
        break;
    }

  } while(1);
}
