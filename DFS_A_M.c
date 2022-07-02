#include"krishna.h"
int top=-1;
int stack[8]={0};
void push(int);
int pop();
int main()
{
 int AM[8][8]={0};
 int visited[8]={0};
 int pos[]={8};
 int node,i;
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
 AM[7][0]=1;
 AM[6][1]=1;
 AM[4][3]=1;
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
 printf("Enter the starting node\n");
 getz(node);
 visited[node]=1;
 push(node);
 printf("Depth first search looks like\n");
 printf("%d-->",node);
 while(top!=-2){
     for(i=0;i<8;i++)
     {
         if(AM[node][i]==1 && visited[i]==0){
             pos[node]=i;
             push(i);
             visited[i]=1;
             printf("%d-->",i);
             node=i;
             i=0;
         }
     }
     node=pop();
     i=pos[node];
 }

  
 return 0;
}
void push(int node){
    stack[++top]=node;
}
int pop(){
    int x=top;
    top--;
    return stack[x];
}