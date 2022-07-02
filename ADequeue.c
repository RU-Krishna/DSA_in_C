#include"krishna.h"
int *arr=NULL,N;
int front =-1;
int rear=-1;
void i_front(int);
void i_rear(int);
int d_rear();
int d_front();
int search(int);
void display();
int main()
{
    char op,ch;
    int num;
    printf("Enter the size of the queue\n");
    getz(N);
    arr=(int *)malloc(sizeof(int)*N);
      flush;
    while(1)
    {
        printf("Choose an option\n");
        printf("1. Insertion from front end\n");
        printf("2. Insertion from rear end\n");
        printf("3. Deletion from front end\n");
        printf("4. Deletion from rear end\n");
        printf("5. Search an element\n");
        printf("6. Display the whole queue\n");
        printf("7. Exit\n");
        gec(op);
        switch(op){
            case '1':
                        printf("Enter the number\n");
                        getz(num);
                        i_front(num);
                        break;
            case '2':
                      printf("Enter the number\n");
                      getz(num);
                      i_rear(num);
                      break;
            case '3':
                       num=d_front();
                       if(num==-99999)
                        printf("Front End Deletion not possible!\n");
                       else
                        printf("%d is removed from the queue\n",num);
                        break;
            case '4':
                       num=d_rear();
                        if(num==-99999)
                        printf("Rear End Deletion not possible!\n");
                       else
                        printf("%d is removed from the queue\n",num);
                        break;
            case '5':  
                        printf("Enter the number to be searched\n");
                        getz(num);
                        if(search(num))
                         printf("Successfull! Element present\n");
                        else
                          printf("Unsuccessfull!Element not found exception\n");
                        break;
           case '6':
                        display();
                        break;
           case '7':
                         exit(0);    
            default :
              printf("Incorrect option\n");
        }
        flush;
    }
}
void i_rear(int num)
{
   if(rear==N-1)
   {
     printf("Queue Overflow! Rear insertion not allowed\n");
     return;
   }
     if(front==-1 && rear==-1)
    {
        front=rear=0;
        arr[rear]=num;
    }
    else
        arr[++rear]=num;
}
void i_front(int num)
{
       if(front<=0)
       {
         printf("Front End Insertion not allowed\n");
         return ;
       }
       else
       {
          front--;
          arr[front]=num;
       }
}
int d_rear()
{
    int val;
    if(front==-1 && rear==-1)
    {
      printf("Queue Underflow! Deletion not allowed\n");
      return -99999;
    }
    if(front==rear)
      {
          val=arr[rear];
          front=-1;
          rear=-1;          
      }
      else{
          val=arr[rear];
          rear--;
      }
     return val;
}
int d_front(){
    int val;
    if(front==-1 && rear==-1)
    {
      printf("Queue Underflow! Deletion not possible\n");
      return -99999;
    }
    if(front==rear)
    {
        val=arr[front];
         front=-1;
         rear=-1;
    }
    else{
        val=arr[front];
        front++;
    }
    return val;
}
int search(int num)
{
    int x=front;
    for(;x<=rear;x++)
        if(arr[x]==num)
          return 1;
    return 0;
}
void display(){
    int x;
    if(front==-1 && rear==-1){
    printf("Queue Empty\n");
    return ;
    }
    for(x=front;x<=rear;x++)
      printf("\t%d\n",arr[x]);
}