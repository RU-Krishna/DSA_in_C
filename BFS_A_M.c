#include"krishna.h"
int front=-1;
int rear=-1;
int queue[8]={0};
void push(int);
int pop();
int main()
{
 int AM[8][8]={0};
 int visited[8]={0};
 int node=0;
 //making the adjacency matrix...
 AM[0][1]=1;
 AM[1][2]=1;
 AM[1][4]=1;
 AM[1][5]=1;
 AM[2][0]=1;
 AM[2][3]=1;
 AM[3][5]=1;
 AM[5][4]=1;
 AM[4][6]=1;
 AM[6][7]=1;
 newscr;
  printf("The Adjacency matrix looks like\n");
  gotoxy(6,1);
  printf("|0 |1 |2 |3 |4 |5 |6 |7 \n");
 //Printing the Adjacency matrix...
 for(int i=0;i<8;i++){
     printf("   --------------------------");
     gotoxy(3,1);
     printf("%d  ",i);
     for(int j=0;j<8;j++)
         printf("|%d ",AM[i][j]);
     printf("\n");
   
 }
 printf("Breadth first traversal looks like:-\n");
 visited[0]=1;
 do
 {
     for(int i=0;i<8;i++)
      if(AM[node][i]==1 && visited[i]==0)
      {
          push(i);
          visited[i]=1;
      }
      printf("%d->",node);
      node=pop();
 } while (node!=-1);
 
return 0;
}
void push(int x)
{
    if(front==-1 && rear==-1)
    { 
        front=rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}
int pop()
{
    int x;
    if(front==-1 && rear==-1)
     return -1;
    if(front==rear && front!=-1)
    {
        x=queue[front];
        front=rear=-1;
    }    
    else{
        x=queue[front];
        front++;
    }

    return x;
}