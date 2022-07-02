#include"krishna.h"
typedef struct CQUEUE{
    char name[30];
    struct CQUEUE *next;
}node;
node *front=NULL;
node *rear=NULL;
void enqueue(char *);
char *dequeue();
int search(char *);
void display(node *);
void empty(node *);
int size(node *);
int main()
{

  char op;
  char name[30];
  while(1){
      printf("       Choose an option\n");
      printf("1. Enqueue\n");
      printf("2. Dequeue\n");
      printf("3. Search for name in the Circular queue\n");
      printf("4. Diplay the Circular Queueu\n");
      printf("5. Empty the Full Queue\n");
      printf("6. Size of the Circular Queue(Used/Empty)\n");
      printf("7. Exit from the LOOP\n");
      gec(op);
      flush;
      switch(op)
      {
          case '1':
                    printf("Enter the name of the memeber\n");
                    gets(name);
                    enqueue(name);
                    break;
          case '2':
                     if(front==NULL && rear==NULL)
                    {
                        printf("Empty Circular queueu\n");
                        break;
                    }
                    char *rem=dequeue();
                    printf("%s memeber is removed from the queueu\n",rem);
                    break;
          case '3':
                    if(front==NULL && rear==NULL)
                    {
                        printf("There is nothing inside an empty world\n");
                        break;
                    }
                    printf("Enter the name of the memeber\n");
                    gets(name);
                    int res=search(name);
                    if(res)
                     printf("%s member is present in the queue\n",name);
                    else
                     printf("%s memeber is absent in the queue\n",name);
                     break;
          case '4':
                    if(front==NULL && rear==NULL)
                    {
                        printf("This is an empty pond...so why u r trying to bath...\n");
                        break;
                    }
                    display(front);
                    break;
          case '5':
                    if(front==NULL && rear ==NULL)
                    {
                        printf("You can't create hunger in a hungry person\n");
                        break;
                    }
                    empty(front);
                    front=NULL;
                    rear=NULL;
                    break;
          case '6':
                    int len=size(front);
                    printf("%d is the length of the circular Queue\n",len);
                    break;
          case '7':
                    exit(0);
          default :
                    printf("You are mad\n");
      }
      flush;
  }
return 0;
}
void enqueue(char *str)
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    strcpy(ptr->name,str);
    if(front==NULL && rear==NULL)
      front=ptr;
    else
      rear->next=ptr;
      rear=ptr;
      ptr->next=front;
}
char *dequeue()
{
    node *ptr;
    char *str;
    str=(char *)malloc(30);
    strcpy(str,front->name);
    if(front==rear && front!=NULL)
      {
          ptr=front;
          front=rear=NULL;
          free(ptr);
      }
      else{
          ptr=front;
          front=front->next;
          rear->next=front;
          free(ptr);
      }
      return str;
}
int search(char *str)
{
    node *ptr;
    for(ptr=front;ptr!=rear;ptr=ptr->next)
    if(!stricmp(str,ptr->name))
    return 1;
    if(!stricmp(rear->name,str))
    return 1;
    return 0;
}
void display(node *ptr)
{
      printf("%s\n",ptr->name);
    if(ptr->next!=front)
      display(ptr->next);
}
void empty(node *ptr)
{
    if(ptr->next!=front)
      empty(ptr->next);
    free(ptr);
    ptr=NULL;
}
int size(node *ptr)
{
  int length;
  if(ptr==NULL)
  return 0;
  if(ptr->next!=front)
  length=1+size(ptr->next);
  else
   return 1;   
  return length;
}
