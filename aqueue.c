#include"krishna.h"
int *arr;
int N;
int front=-1,rear=-1;
void insert();
void delete();
void display();
void empty();
void space();
void changesize();
int main()
{
    char op='0';
    printf("Enter the size of the queue\n");
    getz(N);
    arr=(int*)malloc(sizeof(int));
    flush;
    while(1)
    {
        newscr;
        printf("Enter an option\n");
        printf("1.Insert an elemnt in the queue\n");
        printf("2.Delete an element from the queue\n");
        printf("3.Display the queue\n");
        printf("4.Empty the full queue\n");
        printf("5.Unoocupied space/Total Space\n");
        printf("6.Change the sixze of the queue\n");
        printf("7.exit\n");
        gec(op);
        switch(op)
        {
            case '1':
                      insert();
                      break;
            case '2':
                      delete();
                      break;
            case '3':
                      display();
                      break;
            case '4':
                       empty();
                       break;
            case '5': 
                       space();
                       break;
            case '6':
                        changesize();
                        printf("new size of the queue is %d\n",sizeof(arr));
                        break;
            case '7': 
                        exit(0);
            default :
                       printf("Incorrect Option\n");
                       getch();
        }
        flush;
    }
    return 0;
}
void insert()
{
    if(rear!=N-1)
    {
        printf("Enter the element\n");
        if(front==-1 && rear==-1)
        front++;        
        getz(arr[++rear]);
    }
    else
    {
        printf("Queue Overflow\n");
        getch();
    }

}
void delete()
{
    if(front==rear && front!=-1)
      {
        front=-1;
        rear=-1;
      }
    else if(front!=-1)
       front++;
    else

    {
        printf("Queue underflow\n");
        getch();
    }

}
void display()
{
    int i=front;
    if(front==-1 && rear==-1) 
       printf("Queue is empty\n");
    else
    {
    for(;i<=rear;i++)
     printf("%d\n",arr[i]);
    }
    getch();
}  
void empty()
{
    front=rear=-1;
}
void space()
{
    printf("%d/%d\n",N-1-rear,N);
    getch();
}
void changesize()
{
    printf("Enter the new size of the array\n");
    getz(N);
    arr=realloc(arr,N);
    if(arr==NULL)
    printf("Reallocation failed");
    getch();
}

