#include"krishna.h"
typedef struct linkedlist{
    int info;
    struct linkedlist *next;
}node;
node *head=NULL;
node *tail=NULL;
void insert(int);
int delete(int);
node *search(int);
void print();
int main(){
    int op,num;
    node *loc;
    while (1)
    {
       printf("Choose an option\n");
       printf("1.INSERT An element\n");
       printf("2.DELETE an element\n");
       printf("3.SEARCH an element\n");
       printf("4.PRINT the list\n");
       printf("5.Exit\n");
       scanf("%d",&op);
       switch (op)
       {
       case 1:
           printf("Enter the number\n");
           scanf("%d",&num);
           insert(num);
           break;
       case 2:
           if(head==NULL)
           {
           printf("Empty list\n");
           break;
           }
           printf("Enter the element to be deleted\n");
           scanf("%d",&num);
           if (delete(num)==-9999)
               printf("Number %d is absent\n",num);
           else
               printf("%d is deleted\n",num);
           break;
       case 3:
           if (head==NULL)
           {
               printf("U r searching in empty pond\n");
               break;
           }
           printf("Enter the element to be searched\n");
           scanf("%d",&num);
           loc=search(num);
           if (loc==NULL)
               printf("Element %d is absent\n",num);
           else
               printf("Eement %d is present\n",loc->info);
               break;
       case 4:
           print();
           break;
       case 5:
           exit(0);
                  
       default:
           printf("Please choose from the menu\n");
           break;
       }
    }
return 0;
}
void insert(int num)
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->info=num;
    if(head==NULL)
    {
        ptr->next=NULL;
        head=ptr;
        tail=ptr;
    }
    else
    {
        ptr->next=NULL;
        tail->next=ptr;
        tail=ptr;
    }
}
int delete(int num)
{
    node *ptr,*loc;
    if (head->info==num)
    {
        if(head==tail)
        {
            free(head);
            head=NULL;
            tail=NULL;
        }
        else
        {
            ptr=head;
            head=head->next;
            free(ptr);
        }
    }
    else
    {
        loc=search(num);
        if(loc==NULL)
            return (-9999);
        for(ptr=head;ptr->next!=loc;ptr=ptr->next);
        ptr->next=loc->next;
        free(loc);
    }
    return (num);
}
node *search(int num)
{
    node *ptr;
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    if (ptr->info==num)
      return(ptr);
    if(ptr==NULL)
    return NULL;
    }
void print()
{
    node *ptr;
    if(head==NULL)
    {
        printf("Empty list\n");
        return;
    }
    for(ptr=head;ptr!=tail;ptr=ptr->next)
      printf("%d->",ptr->info);
      printf("%d\n",tail->info);
}