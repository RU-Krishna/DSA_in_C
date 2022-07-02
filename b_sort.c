#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void bubble(int *,int);
void swap(int *,int,int);
int main()
{
    int N,*arr,i;
    printf("Enter the number of elements u wnat to sort\n");
    scanf("%d",&N);
    arr=(int *)malloc(sizeof(int)*N);
    printf("Enter the elements\n");
    for(i=0;i<N;i++)
      scanf("%d",&arr[i]);
       printf("Press a key to start sorting\n");
     getch();
      bubble(arr,N);
    printf("Elements after sorting:-\n");
    for(i=0;i<N;i++)
       printf("%d\n",arr[i]);
       free(arr); //1lakh numbers take average of 26s...
return 0;
}
void bubble(int *arr,int N)
{
    int  i,j;
    for(i=N-1;i>0;i--)
      for(j=0;j<i;j++)
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