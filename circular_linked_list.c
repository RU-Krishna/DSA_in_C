#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct circular_linked_list
{
    char name[30];
    unsigned long long mobile;;
    char address[40];
    struct circular_linked_list *next;
}node;
node *head;
node *tail;
void insert();
int delete();
node *search(char *);
void display();
int main()
{
   int op=0;
   node *loc;
   char str[30];
   while(op!=5)
   {
   printf("SElect an option\n");
   printf("1.Register a person\n");
   printf("2.Delete the data of a person\n");
   printf("3.Search for an person\n");
   printf("4.Display the whole data of persons\n");
   printf("5.Exit\n");
   scanf("%d",&op);
   fflush(stdin);
   switch (op)
   {
       case 1:
               insert();
               break;
       case 2:
              if(head==NULL)
              {
                printf("Ocean is empty\nU can't remove anything from it\n");
                break;
              }
               if(delete()==1)
                 printf("person is deleted from the list\n");
                else
                 printf("Person is absent in the list\n");
               break;
       case 3:
               if(head==NULL)
               {
                 printf("List is empty\n");
                 break;
               }
               printf("Enter the name of the person\n");
               gets(str);
               loc=search(str);
               if(loc==NULL)
                 printf("U r finding the wrong person\n");
               else
                 printf("%s person is present in the list\n",loc->name);
                 break;
       case 4:
               if(head==NULL)
               {
                 printf("List is empty\n");
                 break;
               }
               display();
               break;
              
       default:
                printf("Hey! Buddy choose the correct option\n");
                break;
   }
   }
     return 0;
}
void insert()
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    printf("Enter the name of the person\n");
    gets(ptr->name);
    printf("Enter the mobile number of the person\n");
    scanf("%llu",&ptr->mobile);
    fflush(stdin);
    printf("Enter the address of the person\n");
    gets(ptr->address);   
    while((getchar())!='\n');
   
    ptr->next=head;
    if(head==NULL)
    {
        head=ptr;
        tail=ptr;       
    }
    else
    {
        tail->next=ptr;
        tail=ptr;
    }
}
int delete()
{
    char str[30];
    node *loc,*ptr;
    printf("Enter the name of the person\n");
    gets(str);
    if(strcmp(head->name,str)==0)
    {
        if(head!=tail)
        {
            ptr=head;
            head=head->next;
            tail->next=head;
            free(ptr);
        }
        else
        {
            ptr=head;
            head=tail=NULL;
            free(ptr);
        }
        return 1;
    }  
    loc=search(str);
    if(loc==NULL)
      return 0;
    else
    {
      for(ptr=head;ptr->next!=loc;ptr=ptr->next);
         ptr->next=loc->next;
         free(loc);
         if(loc==tail)
            tail=ptr;
          return 1;
    }
}
node* search(char *s)
{
    node *ptr;
    for(ptr=head;ptr->next!=head;ptr=ptr->next)
      if(strcmp(ptr->name,s)==0)
        return ptr;
    if(strcmp(tail->name,s)==0)
      return tail;
    else
      return NULL;
}  
void display()
{
    node *ptr;
    int s=1;
       printf("-----------------------------------------------------------------------------------------------\n");
       printf("|S.no. |Name\t\t\t      |Address\t\t\t\t       |Mobile no.   |\n");
       printf("-----------------------------------------------------------------------------------------------\n");
    for(ptr=head;ptr!=tail;ptr=ptr->next)
    {
       printf("|%-6d|%-30s|%-40s|%-13llu|\n",s++,ptr->name,ptr->address,ptr->mobile);
       printf("-----------------------------------------------------------------------------------------------\n");
    }
     printf("|%-6d|%-30s|%-40s|%-13llu|\n",s++,ptr->name,ptr->address,ptr->mobile);
       printf("-----------------------------------------------------------------------------------------------\n");
}

