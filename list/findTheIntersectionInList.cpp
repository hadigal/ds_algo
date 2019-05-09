#include<iostream>
#include<stdio.h>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
int intersectPoint(struct Node* head1, struct Node* head2);
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;
    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }
        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node
struct Node {
    int data;
    struct Node* next;
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here

    if(head1 == NULL || head2 == NULL)
    {
        return -1;
    }

    Node *itr1 = head1;
    Node *itr2 = head2;

    int nCount1 = 0;
    int nCount2 = 0;

    int diffCount, tmp = 0;

    while(itr1 != NULL || itr2 != NULL)
    {
        if(itr1 != NULL)
        {
            ++nCount1;
            itr1 = itr1->next;
        }

        if(itr2 != NULL)
        {
            ++nCount2;
            itr2 = itr2->next;
        }
    }

    diffCount = nCount1 - nCount2;
    diffCount = (diffCount < 0)?-diffCount:diffCount;

    if(nCount1 > nCount2)
    {
        itr1 = head1;
        while(itr1 != NULL)
        {
            ++tmp;
            itr1 = itr1->next;
            if(tmp == diffCount)
            {
                itr2 = head2;
                break;
            }
        }
    }
    else
    {
        itr2 = head2;
        while(itr2 != NULL)
        {
            ++tmp;
            itr2 = itr2->next;
            if(tmp == diffCount)
            {
                itr1 = head1;
                break;
            }
        }
    }

    while(itr1 != NULL && itr2 != NULL)
    {
        if(itr1 == itr2)
        {
            return itr1->data;
        }
        itr1 = itr1->next;
        itr2 = itr2->next;
    }

    return -1;
}
