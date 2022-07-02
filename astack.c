#include"krishna.h"
int N;
int *arr;
int top=-1;
void push(int);
int pop();
void empty();
void display();
void size();
int main()
{
    char op;
    int num;
    printf("Enter the size of the array\n");
    getz(N);
    arr=(int *)malloc(sizeof(int)*N);  //allcoating chunk of memory for the user...
    while(1)
    {
         flush;  //flush the enter for the next char value...
        printf("Choose an option:-\n");   //menu for the user...
        printf("1.Push into the stack\n");
        printf("2.Pop out of the stack\n");
        printf("3.Empty the full stack\n");
        printf("4.How many elements in the stack(remining/filled)\n");
        printf("5.Watch the full stack\n");
        printf("6.exit\n");
        gec(op);
        switch(op)  //switching to the option chosen by the user...
        {  
            case '1':
                      if(top==N-1)
                      {   
                          newscr;
                          gotoxy(15,8);
                          printf("*********Stack overflow**********\n");
                          getch();
                          newscr;
                          break;
                      }
                      else
                      {
                      printf("Enter the element\n");
                      getz(num);
                      push(num);  
                      break;
                      }

            case '2':
                      num=pop();
                      printf("%d is removed from the stack\n",num);
                      break;
            case '3':
                       empty();
                       break;
            case '4':
                       size();
                       break;
            case '5':
                      display();
                      break;
            case '6':
                       exit(0);
            default :
                       printf("Incorect option\n");
        }
    }
return 0;
}
void push(int num)
{
        arr[++top]=num;
}
int pop()
{
    if(top==-1)
    {   newscr;
        gotoxy(15,8);
        printf("*******stack underflow***********\n");
        getch();
        newscr;
    }
    else
    {
        int num=arr[top];
        arr[top--]=0;
        return num;
    }   
}
void empty()
{
    for(;top!=-1;top--)
    {
       arr[top]=0;
    }
}
void size()
{
    printf("%d elements are filled in the stack\n",top+1);
    printf("%d locations are free to use\n",N-top-1);
}
void display()
{
    int pos;
    if(top!=-1)
    {
     printf("|----|\n");
    for(pos=top;pos!=-1;pos--)
    { 
        printf("| %d  |\n",arr[pos]);
        printf("|----|\n");
    }
    }
    else 
      printf("Empty stack\n");
}

