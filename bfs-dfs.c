#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
typedef struct node
{    int vertex;
    struct node *next;
}node;
typedef node *nodeptr;
nodeptr graph[30];
int q[30]={0};
int i=0,visited[30]={0},front=0,rear=0;
void addq(int v)
{q[rear++]=v;}
int deleteq()
{return(q[front++]);}

void BFS(int v)
{    nodeptr temp;
    printf("%d ",v);
    visited[v]=TRUE;
    front=0;
    rear=0;
    addq(v);
    while(front<=rear)
    {   v=deleteq();
        for(temp=graph[v];temp;temp=temp->next){
            if(!visited[temp->vertex])
        {
            printf("%d ",temp->vertex);
            addq(temp->vertex);
            visited[temp->vertex]=TRUE;}
        }
    }
}
void insert(int vi,int vj)
{node *p,*q;
 q=(node *)malloc(sizeof(node));
 q->vertex=vj;
 q->next=NULL;
 if(graph[vi]==NULL)
  graph[vi]=q;
 else
 {
  p=graph[vi];
  while(p->next!=NULL)
   p=p->next;
  p->next=q;
 }
}
void readgraph()
{  int i,vi,vj,no_of_edges,n;
 printf("\nEnter no. of vertices :");
 scanf("%d",&n);
 for(i=0;i<n;i++)
  graph[i]=NULL;
 printf("\nEnter no of edges :");
 scanf("%d",&no_of_edges);
 for(i=0;i<no_of_edges;i++)
 {  printf("\nEnter an edge (u,v)  :");
  scanf("%d%d",&vi,&vj);
  insert(vi,vj);
  insert(vj,vi);
 }
}
void DFS(int v)
{ node *p;
 visited[v]=1;
 printf("\n%d",v);
 for(p=graph[v];p;p=p->next)
 	if(!visited[p->vertex])
 		DFS(p->vertex);
}
int main()
{
 int i,op,n;
 do
   { printf("\n\n1)Create\n2)BFS\n3)dfs\n4)quit");
     printf("\nEnter Your Choice: ");
     scanf("%d",&op);
     switch(op)
      { case 1: readgraph();break;
        case 2: printf("\nStarting Node No. : ");
         scanf("%d",&i);
         BFS(i);break;
        case 3:for(i=0;i<n;i++)
                {visited[i]=0;}
         printf("\nStarting Node No. : ");
         scanf("%d",&i);
         DFS(i);break;
       }
    }while(op!=4);
}
