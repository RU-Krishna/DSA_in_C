#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void mergesort(int *,int);   
void merge(int *,int,int *,int);
int main()
{
    int *arr,N;
    printf("Enter the size of the array\n"); 
    scanf("%d",&N);
    arr=(int *)malloc(sizeof(int)*N);
    printf("Enter the elements of the array\n"); 
      for(int i=0;i<N;i++)
         scanf("%d",&arr[i]);  
         printf("Enter a key to start sorting...");
         getch();
    mergesort(arr,N);  
    printf("Elemnts after sorting looks like\n");
      for(int i=0;i<N;i++)
        printf("%d\n",arr[i]); 
return 0;
}
void mergesort(int *arr,int size)
{   
    if(size>1)  
    {
        int mid=size/2; 
        mergesort(arr,mid);  
        mergesort(arr+mid,size-mid);  
        merge(arr,mid,arr+mid,size-mid);   
    }
}
void merge(int *a,int x,int *b,int y)  
{
 int i=0,j=0,k=0;   
 int *temp; 
 temp=(int *)malloc(sizeof(int)*(x+y));  
 while(i<x && j<y){  
     if(a[i]>b[j])
        temp[k++]=b[j++];
    else
        temp[k++]=a[i++];
 }
 while(i<x)  
   temp[k++]=a[i++];
 while(j<y)
   temp[k++]=b[j++];

   for(int z=0;z<x+y;z++) 
    a[z]=temp[z];

    free(temp); 
}
