#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void insertion(int *,int);
int main()
{
    int *arr,N,i;
    printf("Enter how many elements u want to sort\n");
    scanf("%d",&N);
    arr=(int *)malloc(sizeof(int)*N);
    printf("Enter the %d elemments\n",N);
    for(i=0;i<N;i++)
      scanf("%d",&arr[i]);
      printf("Press a key to start sorting\n");
     getch();
    insertion(arr,N);
    printf("Sorted elements are\n");
     for(i=0;i<N;i++)
      printf("%d\n",arr[i]);  
      free(arr);  
return 0;
}
void insertion(int *arr,int N)
{
    int temp,i,j;
    for(i=1;i<N;i++)
    {
        temp=arr[i];
       for(j=i-1;temp<arr[j] && j>=0;j--)
        arr[j+1]=arr[j];
          arr[j+1]=temp;
    }
}