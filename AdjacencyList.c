#include"krishna.h"
struct Adjacency_List{
    int id;
    struct Adjacency_List *edge[5];
}node[5];
void display();
int main()
{
    int i,j;
    char con;
    newscr;
    for(i=0;i<5;i++)
    {
        node[i].id=i;
        for(j=0;j<5;j++){
            printf("Is there a connection between Node %d & %d(y/n) :-",i+1,j+1);
            gec(con);
            flush;
            if(con=='y')
            node[i].edge[j]=&node[j];
            else
            node[i].edge[j]=NULL;
        }
        
    }
    display();
  
return 0;
}
void display()
{
    int i,j;
    for(i=0;i<5;i++)
    {
       printf("Nodes connected from node %d are:-",node[i].id+1);
       for(j=0;j<5;j++){
           if(node[i].edge[j]!=NULL)
           printf(" -->%d",node[i].edge[j]->id+1);
       }
       printf("\n");
    }
}