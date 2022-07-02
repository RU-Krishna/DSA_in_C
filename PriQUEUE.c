#include"krishna.h"
typedef struct PriQUEUE
{
    char str[30];
    int pri;
    struct PriQUEUE *next;
}node;
node *front=NULL;
node *rear=NULL;
void enqueue(char*,int);
char *dequeue();
int search(char *);
void display(node *);
void empty();
int size(node *);
int main()
{
    char op,*name;
    name=(char *)malloc(255);
    int num,result;
    int prio;
    while(1)
    {
    printf("Choose an operation\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Search an element in the queue\n");
    printf("4. Dispaly the queue\n");
    printf("5. Empty the queue\n");
    printf("6. Size of the queue\n");
    printf("7. Exit\n");
    scanf("%c",&op);
    flush;
    switch(op) 
    {
        case '1':
                  printf("Enter the name\n");
                  gets(name);
                  while(1)
                  { 
                    printf("Enter the priority\n");
                    getz(prio);
                    if(prio>0)
                     break;
                    else
                     printf("Priority must be a natural number\n Try again...\n");
                  }
                     
                  enqueue(name,prio);
                  break;
        case '2':
                  if(front==NULL && rear==NULL)
                  {
                   printf("Empty Queue!Operation not possible\n");
                   break;
                  }
                  name=dequeue();
                  printf("%s is removed from the queue\n",name);
                  break;
        case '3':
                  if(front==NULL && rear==NULL)
                  {
                   printf("Empty queue ! Search is not possible");
                   break;
                  }
                  printf("Enter the member to be searched in the queue\n");
                  gets(name);
                  result=search(name);
                  if(result)
                    printf("Member %s is preseent in the queueu\n",name);
                 else 
                    printf("Member %s is absent in the queue\n",name);
                  break;
        case '4':
                   if(front==NULL && rear==NULL)
                  {
                   printf("Empty Queue!Nothing to show...\n");
                   break;
                  }
                  display(front);
                  break;
        case '5':
                  empty();
                  break;
        case '6':
                  num=size(front);
                  printf("%d members are in the queue\n",num);
                  break;
        case '7': 
                  exit(0);
        default :
                  printf("Don't try to jump in the empty pool\n");
    }
    flush;
    }
return 0;
}
void enqueue(char *name,int prio)
{
    node *ptr;
    int flag=0;
    ptr=(node *)malloc(sizeof(node));
    strcpy(ptr->str,name);
    ptr->pri=prio;
    ptr->next=NULL;
    if(front==NULL && rear==NULL)
    {
       front=rear=ptr;
       flag=1;
    }
    if(prio<front->pri)
    {
      ptr->next=front;
      front=ptr;
      flag=1;
    }
    else if(prio>rear->pri)
    {
      rear->next=ptr;
      rear=ptr;
      flag=1;
    }
    else
    {
      for(node *insert=front;insert!=rear;insert=insert->next)
      {
        node *check=insert->next;
        if(prio>insert->pri && prio<check->pri)
        {
          insert->next=ptr;
          ptr->next=check;
          flag=1;
        }
      }
    }
    if(!flag)
     printf("You are trying to put two persons with same priority...\n This is not possible...\nTry Again...\n");

}
char *dequeue()
{
    node *ptr;
    char *str;
    str=(char *)malloc(255);
    strcpy(str,front->str);
    if(front==rear && front!=NULL)
     {
         free(front);
         front=rear=NULL;
     }
     else
     {
        ptr=front;
        front=front->next;
        free(ptr); 
     }
     return str;     
}
int search(char *name)
{
    node *ptr;
    for(ptr=front;ptr!=NULL;ptr=ptr->next)
        if(!stricmp(name,ptr->str))
        return 1;
    if(ptr==NULL)
     return 0;
}
void display(node *ptr)
{
    if(ptr!=NULL)
      printf("%s  %d\n",ptr->str,ptr->pri);
    if(ptr->next!=NULL)
      display(ptr->next);
      return ;
}
int size(node *ptr)
{ 
   int length;
   if(ptr==NULL)
    return 0;
   else
    length=1+size(ptr->next);
  return length;
}
void empty()
{
   node *ptr,*del;
   for(ptr=front;ptr!=NULL;ptr=ptr->next)
   {
       del=ptr;
      free(del);
   }
   front=rear=NULL;
}
      
    

