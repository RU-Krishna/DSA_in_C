#include"krishna.h"
int b_search(int *,int,int);
int main()
{
    int N,loc,i,key=0;
    printf("How many numbers\n");
    scanf("%d",&N);
    int arr[N];
    printf("Enter the numbers\n");
    for(i=0;i<N;i++)
     scanf("%d",&arr[i]);
     bubble(arr,N);
     while(1)
     {
         printf("Enter the key to be searched\n(-1 to exit)\n");
         scanf("%d",&key);
         if(key==-1)
          exit(0);
         loc=b_search(arr,N,key);
         if(loc==-1)
           printf("%d is absent in the list\n",key);
         else
           printf("%d is present \n",key);
     }
     return 0;
}
int b_search(int *arr,int r,int key)
{
    int l=0,mid;
    while(l<=r)
    {
      mid=(l+r)/2;
      if(arr[mid]==key)
        return mid;
      if(key<arr[mid])
        r=mid-1;
      else
        l=mid+1;
    }
    return -1;
    
}