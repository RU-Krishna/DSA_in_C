#include"krishna.h"
int l_search(int *,int,int);
int main()
{
  int N,key=0,i,loc;
  printf("Enter the number of elements\n");
  getz(N);
  int arr[N];
  printf("Enter the elements\n");
  for(i=0;i<N;i++)
  getz(arr[i]);
  while(1)
  {

   printf("Enter the element to be searched\n(-1 to exit)\n");
  getz(key);
  if(key==-1)
    exit(0);
  loc=l_search(arr,N,key);
  if(loc==-1)
    printf("%d is absent in the list\n",key);
  else 
    printf("%d is present at %d location\n",key,loc);
  }
return 0;
}
int l_search(int *arr,int size,int key)
{
    int i;
    for(i=0;i<size;i++)
      if(arr[i]==key)
        return ++i;
    if(i==size)
     return -1;
}