#include"krishna.h"
void quicksort(int *,int,int);
int main()
{
  int *arr,N;
  printf("Enter the size of the array\n");
  scanf("%d",&N);
  arr=(int *)malloc(sizeof(int)*N);
  printf("Enter the elements\n");
  for(int i=0;i<N;i++)
  getz(arr[i]);
  printf("Press any key to sort\n");
  respond;
  quicksort(arr,0,N-1);
  printf("Elements after sorting equals\n");
  for(int i=0;i<N;i++)
   printf("%d\n",arr[i]);
  free(arr);
return 0;
}
void quicksort(int *arr,int l,int r)
{
    int i=l;
    int j=r;
    int pivot=arr[l];
    int lt;
    while(i<j){
        for(;arr[j]>=pivot && i<j;j--);
        if(i<j)
        {
        arr[i]=arr[j];
        i++;
        }
        for(;arr[i]<=pivot && i<j;i++);
        if(i<j){
        arr[j]=arr[i];
        j--;
        }
    }
     lt=i;
    arr[lt]=pivot;
    if(lt>l)
      quicksort(arr,l,lt-1);
    if(lt<r)
      quicksort(arr,lt+1,r);
}
