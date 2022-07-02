#include"krishna.h"
#define hash(value) value%10;
int arr[10];
void insert(int);
void delete(int);
int search(int);
void display();
int main()
{
  char op;
  int val;
  while(1){
    printf("Choose an option\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    gec(op);
    switch(op){
      case '1':
                 printf("Enter an element\n");
                 getz(val);
                 insert(val);
                 break;
      case '2':
                 printf("Enter the element to be deleted\n");
                 getz(val);
                 delete(val);
                 break;
      case '3':
                 printf("Search for the element\n");
                 getz(val);
                 if(search(val))
                   printf("Element present\n");
                 else 
                    printf("Element unsuccessfull\n");
                 break;
      case '4':
                 display();
                 break;
      case '5':
                 exit(0);
      default :
                 printf("Incorrect option\n");
    }
    flush;
  }

return 0;
}
void insert(int val)
{
  int hashcode=hash(val);
  arr[hashcode]=val;
}
void delete(int val)
{
  int hashcode= hash(val);
  arr[hashcode]=0;
}
int search(int val){
  int hashcode=hash(val);
  if(arr[hashcode=val])
    return 1;
  else
   return 0;
}
void display()
{
  for(int i=0;i<10;i++)
    printf("%d= %d\n",i,arr[i]);
}