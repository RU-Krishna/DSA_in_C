#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void selection(int *,int);
void swap(int *,int,int);
int main()
{
    int N,*arr,i;
    printf("Enter the number of elements u wan t to sort\n");
    scanf("%d",&N);
    arr=(int *)malloc(sizeof(int)*N);
    printf("Enter the elemets\n");
    for(i=0;i<N;i++)
      scanf("%d",&arr[i]);
       printf("Press a key to start sorting\n");
     getch();
    selection(arr,N);
    printf("Sorted elements are\n");
    for(i=0;i<N;i++)
      printf("%d\n",arr[i]);
      free(arr);  //26second average...
return 0;
}
void selection(int *arr,int N)
{
    int i,j;
    for(i=0;i<N-1;i++)
      for(j=i+1;j<N;j++)
       if(arr[i]>arr[j])
        swap(arr,i,j);
}
void swap(int *num,int i,int j)
{
    int temp;
    temp=num[i];
    num[i]=num[j];
    num[j]=temp;
}