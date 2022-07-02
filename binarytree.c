/*
    Binary Search Tree Program...
    Creator:- Krishna Purwar...
    Program is in fullfledged working state...

    Binary Search Tree:-
      "A binary tree which holds the binary search property..."  


    Binary Search Property:-
       "If we have a root node 'r' and we have to insert another node 'x' in the tree then:-
        * x is inserted in the left subtree of 'r' if x.key<r.key...
        * x insrted in the right subtree of 'r' if x.key>r.key... "
        Now this property holds for each inserting element in the tree...
         

  //Below is the given program for binary search tree...
 */


#include"krishna.h"
typedef struct binarytree
{                                       //Structure of the binary tree...
    int info;
    struct binarytree *left,*right;   
}node;                                  //Calling Single Element of this binary tree a node...
node *root=NULL;       //Declaring and initialising  the root node of the tree globally as null...

/*
     Prototype declaration of all the functions applied on the tree...
     These functions are in the following order of process...
     1.Inserting an elementing in the tree...
     2.Deleting an element from the tree...
     3.Searching an element in the tree...
     4.Inorder treaversal of the tree...
     5.Preorder traversal of the tree...
     6.Postorder traversal of the tree...
     7.Minimum element in the subtree of given node of the tree...
     8.Maximum element in the subtree of given node of the tree...
     9.Parent node of the tree...
     10.Sucessor node of the tree... 
     11.Predecessor node of the tree...  


*/
                
node* insert(node *,int);                
node* delete(node*,int);
int search(int);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *tree_min(node *root);
node *tree_max(node *root);
node *parent(node *,node *); 
node *successor(node *);
node *predecessor(node *);
int main()
{
    int num;        //Variable 'num' to take the value to be stored in the tree...
    char ch;        //Character variable for recieving the option chosen by the user...
    int loc;         // Used in the searching case of the programm...
    while(1)
    {  
      /*
             MENU OPTIONS TO BE AVAILABLE TO THE USER ON THE TERMINAL PHASE...

      */
        printf("\n\nChoose an option\n");
        printf("1. Insert an element in the tree\n");
        printf("2. Delete an element from the tree\n");
        printf("3. Search an element in the tree\n");
        printf("4. Display an tree\n");
        printf("5. Minimum element in the tree\n");
        printf("6. Maximum element in the tree\n");
        printf("7. exit()\n");
        scanf("%c",&ch);     //Recieve the input option by the user as a char...
        switch(ch)
        {
          /* 
                  All the cases belonging to the menu + Default case...
          */
            case '1':
                    
            case '2':
                     if(root==NULL)                    //Cheeking for the empty tree before recieving the element for deletion...
                     {
                      printf("Tree is empty\n");
                      break;
                     }
                     printf("Enter the element to delete\n");
                     getz(num);
                     root=delete(root,num);
                     break;
            case '3':
                     if(root==NULL)
                     {    //Checking for the empty tree before recieving an element for the searching...
                      printf("Tree is empty\n");
                      break;
                     }
                     printf("Enter the Element to be searched\n");
                     getz(num);
                     loc=search(num);
                     if(loc==-1)      //If integer value returned by the search function is '-1'...then it means element is absent...
                       printf("Element is absent in the tree");
                     else
                       printf(" %d is present.\n",num);
                     break;
            case '4':
                      
                     if(root==NULL)
                     {                     //Checking for empty tree before tree traversal...
                       printf("null tree\n");
                       break;
                     }
                      newscr;     //Clearling the whole screen...For new menus for traversal...
                      flush;     //Removing the 'newline' keyboard buffer so that it cannot be accepted by 'op'...
                      char op;
                      printf("a. Inorder Tree\n");
                      printf("b. PreOrder Tree\n");
                      printf("c. PostOrder Tree\n");
                      gec(op);
                      if(op=='a')
                         inorder(root);
                      else if(op=='b')
                          preorder(root);
                      else if(op=='c')
                          postorder(root);
                      else 
                         printf("Bad work... Try it next time\n");
                     break;
            case '5':
                    if(root==NULL)
                         {                               //Checking for empty tree before finding the tree minimum value...
                          printf("Tree is empty\n");
                          break;
                         }
                    node *min=tree_min(root); 
                    printf("%d is the smallest element in the tree\n",min->info); 
                    node *suc=successor(root->left->left->right);
                    if(suc!=NULL)
                    printf("%d is the successor of the min element\n",suc->info);     
                    else 
                    printf("No successor element...\n");            
                    break;     
            case '6':
                      if(root==NULL)
                         {                             //Checking for the empty tree before finding tree maximum value...
                          printf("Tree is empty\n");
                          break;
                         }
                    node *max=tree_max(root);
                    printf("%d is the largest element in the tree\n",max->info);
                     node *pre=predecessor(max);
                    if(pre!=NULL)
                    printf("%d is the predecessor of the min element\n",pre->info);     
                    else 
                    printf("No predecessor element...\n");
                    break;          
            case '7':
                     exit(0);
                     break;   //Taking exit from the menu cycle...
            default :
                      printf("Incorrect option try again\n");    //Default case for incorrect option...
        }
           flush;    //Clearing the input stream for taking new values...
    }

return 0;
}
node *insert(node *r,int num)
{
    if(r==NULL)
    { 
      r=(node *)malloc(sizeof(node));
      r->info=num;
      r->left=NULL;
      r->right=NULL;  
    }
    else
    {
      if(r->info>num)
        r->left=insert(r->left,num);
      else if(r->info<num)
        r->right=insert(r->right,num);
      else if(r->info==num)
        printf("Duplicate elements\n");
    }
    return r;
}
node* delete(node *r,int num)
{
  node *ptr;
  if(r==NULL)
  {
    printf("Element absent in the tree\n");
    return NULL;
  } 
  else if(r->info<num)
  r->right=delete(r->right,num);
  else if(r->info>num)
  r->left=delete(r->left,num);
  else 
  {
    if(r->right==NULL && r->left==NULL)
    {
      free(r);
      return NULL;
    }
    else if(r->right==NULL)
    {
      ptr=r->left;
      free(r);
      return(ptr);
    }
    else
    {
      ptr=r->left;
      while(ptr->right!=NULL)
      ptr=ptr->right;
      r->info=ptr->info;
      r->left=delete(r->left,ptr->info);
    }
  }
  return r;
}
int search(int num)
{
  node *ptr;
  ptr=root;
  while(ptr!=NULL)
  {
    if(ptr->info>num)
    ptr=ptr->left;
    else if(ptr->info<num)
    ptr=ptr->right;
    else if(ptr->info==num)
    return (num);
  }
  return -1;  
}
void inorder(node *ptr)
{
  if(ptr!=NULL){
    inorder(ptr->left);
    printf("%d->",ptr->info);
    inorder(ptr->right);
  }
}
void preorder(node *ptr){
  if(ptr!=NULL){
    printf("%d->",ptr->info);
    preorder(ptr->left);
    preorder(ptr->right);
  }
}
void postorder(node *ptr){
  if(ptr!=NULL){
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d->",ptr->info);
  }
}
node *tree_min(node *ptr){
  while(ptr->left!=NULL)
    ptr=ptr->left;
  return ptr;
}
node *tree_max(node *ptr){
  while(ptr->right!=NULL)
    ptr=ptr->right;
  return ptr;
}
node *parent(node *ptr,node *child)
{ 
  
    if(ptr->info>child->info && ptr->left!=NULL)
     {
       if(ptr->left->info==child->info)
          return ptr;
       else
          return parent(ptr->left,child);
     }
     else if(ptr->info<child->info && ptr->right!=NULL)
     {
         if(ptr->right->info==child->info)
          return ptr;
       else
          return parent(ptr->right,child);
      
     }
     return NULL;
}
node *successor(node *ptr){
  node *big=NULL;
  if(ptr->right!=NULL)
     return tree_min(ptr->right);
  else
  {
      big=parent(root,ptr);
      while(big!=NULL && big->right==ptr)
      {
        ptr=big;
        big=parent(root,ptr);
      }
      return big;
  }
  return NULL;
 
}
node *predecessor(node *ptr)
{
   node *small=NULL;
  if(ptr->left!=NULL)
    return tree_max(ptr->left);
  else
  {
    small=parent(root,ptr);
    while(small!=NULL && small->left==ptr)
    {
      ptr=small;
      small=parent(root,ptr);
    }
    return small;
  }
  return NULL;
}