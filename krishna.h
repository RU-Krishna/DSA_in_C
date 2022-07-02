#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define flush while((getchar())!='\n')
#define newscr system("cls")
#define getz(n) scanf("%d",&n)
#define gec(ch) scanf("%c",&ch)
#define getf(f) scanf("%f",&f)
#define respond getch()
void swap(int *,int,int);
void bubble(int *arr,int N)
{
    int  i,j;
    for(i=0;i<N-1;i++)
      for(j=0;j<N-1;j++)
        if(arr[j]>arr[j+1])
        swap(arr,j,j+1);        
}
void swap(int *s,int i,int j)
{
    int temp;
    temp=s[i];
    s[i]=s[j];
    s[j]=temp;
}
void gotoxy(int x,int y){
  
  for(;y>0;y--)
   printf("\n");
  for(;x>0;x--)
  printf(" ");
}