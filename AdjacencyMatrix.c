#include"krishna.h"
int main()
{
 int arr[5][5]={0}; 
 

 arr[0][1]=1;
 arr[1][2]=1;
 arr[1][4]=1;
 arr[2][3]=1;
 arr[3][1]=1;
 arr[0][3]=1;
 arr[4][2]=1;

  printf("The Adjacency matrix looks lik\n");
  gotoxy(6,1);
  printf("|0 |1 |2 |3 |4 \n");
 //Printing the Adjacency matrix...
 for(int i=0;i<5;i++){
     printf("   ------------------");
     gotoxy(3,1);
     printf("%d  ",i);
     for(int j=0;j<5;j++)
         printf("|%d ",arr[i][j]);
     printf("\n");

 }

return 0;
}