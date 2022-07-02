#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Doubly_link
{
    char name[30];
    struct Doubly_link *next,*pre;
}node;
node *head=NULL;
node *tail=NULL;
void insert();
int delete();
node *search(char *);
void display();
int main()
{
    int op;
    node *loc;
    char str[30];
    while(1)
    {
       printf("Choose an option\n");
       printf("1.Insert  a name\n");
       printf("2.Delete A name\n");
       printf("3.Search a node\n");
       printf("4.Display the list\n");
       printf("5.Exit\n");
       scanf("%d",&op);
       switch (op)
       {
       case 1:
           fflush(stdin);
           insert();
           break;
       case 2:
           if(head==NULL)
           {
               printf("U r trying to suck water from an empty well!\n");
               break;
           }
            fflush(stdin);
            if(delete()!=1)
              printf("Person absent\n");
            else
              printf("Person is deleted form the list\n");
            break;    
       case 3:
           if(head==NULL)
           {
               printf("U r trying to find laptop in furniture house\n");
               break;
           }
            fflush(stdin);
            printf("Enter the name u want to search\n");
            gets(str);
             loc=search(str);
             if(loc==NULL)
               printf("Person is absent in the list\n");
             else
               printf("%s is present in the list\n",loc->name);
           break; 
       case 4:
           display();
           break;
       case 5:
           exit(0);          
       default:
           printf("Incorrect option\n");
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
    ptr->next=NULL;
    if(head==NULL)
    {
        head=tail=ptr;
        ptr->pre=NULL;
    }
    else
    {
        tail->next=ptr;
        ptr->pre=tail;
        tail=ptr;
    }
}
 int delete()
 {
   node *ptr,*loc;
   char str[30];
   printf("Enter the name of the person\n");
   gets(str);
   if(strcmp(head->name,str)==0)
   {
         ptr=head;
     if(head==tail)
           head=tail=NULL;
       else
       {
           head->next->pre=NULL;
           head=head->next; 
       }
       free(ptr);
       return 1;
   }
   loc=search(str);
   if(loc==NULL)
         return 0;
   for(ptr=head;ptr->next!=loc;ptr=ptr->next);
       ptr->next=loc->next;
       if(loc!=tail)
         loc->next->pre=ptr;   
       else
         tail=loc->pre;   
   free(loc);
   return 1;
 }
 node *search(char *str)
 { 
    node *ptr;
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    if(strcmp(ptr->name,str)==0)
     return ptr;

    if(ptr==NULL)
      return NULL; 
 }
 void display()
 {
   node *ptr;
   if(head==NULL)
   {
     printf("Empty pond!!\n");
     return;
   }
   printf("----------------------------------------------\n");
   printf("|\t\t\"NAMES IN THE LIST\"  \t|\n");
   printf("----------------------------------------------\n");
   for(ptr=head;ptr!=NULL;ptr=ptr->next)
   {
       printf("|%-30s \t|\n",ptr->name);
       printf("----------------------------------------------\n");
   }
 }