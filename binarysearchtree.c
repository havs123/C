#include<stdio.h>
#include<stdlib.h>
#define COM(x,y) ((x) > (y) ? 1 : ( (x) < (y) ? -1 : 0 ) )
typedef struct node
{   int data ;
   struct node* llink ;
   struct node* rlink ;
 }* Tree ;
Tree root = NULL ;
void insert ( int item )
 {
   Tree temp = root , tmp ;
   int flag = 0 ;
   if( root == NULL )
      {   root = (Tree)malloc(sizeof(*root)) ;
          root->data = item  ;
          root->llink = NULL ;
          root->rlink = NULL ;
      }
    else
      {
        while(flag == 0 )
          {
             switch(COM(item,temp->data))
               {
                  case(1) :
                      {
                          if( temp->rlink == NULL )
                            {
                              tmp = (Tree)malloc(sizeof(*tmp)) ;
                              temp->rlink = tmp ;
                              tmp->data = item ;
                              tmp->llink = tmp->rlink = NULL ;
                              flag = 1 ;
                            }
                           else
                            {
                              temp = temp->rlink ;
                             }
                           break ;
                      }
                   case(0) :
                      {
                         printf("%d already in the tree\n",item) ;
                         flag = 1 ;
                         break ;
                      }
                    case(-1) :
                      {
                          if( temp->llink == NULL )
                            {
                              tmp = (Tree)malloc(sizeof(*tmp)) ;
                              temp->llink = tmp ;
                              tmp->data = item ;
                              tmp->llink = tmp->rlink = NULL ;
                              flag = 1 ;
                            }
                           else
                            {
                              temp = temp->llink ;
                             }
                           break ;
                      }
                  }
              }
        }
 }
Tree search ( int item )
 {
   Tree temp = root , tmp ;
   int flag = 0 ;
   if( root == NULL )
      {
         /* root = (Tree)malloc(sizeof(*root)) ;
          root->data = item  ;
          root->llink = NULL ;
          root->rlink = NULL ; */ return NULL ;
      }
    else
      {
        while(flag == 0 )
          {
             switch(COM(item,temp->data))
               {
                  case(1) :
                      {
                          if( temp->rlink == NULL )
                            {
                             /* tmp = (Tree)malloc(sizeof(*tmp)) ;
                              temp->rlink = tmp ;
                              tmp->data = item ;
                              tmp->llink = tmp->rlink = NULL ; */
                              flag = 1 ; return NULL ;
                            }
                           else
                            {
                              temp = temp->rlink ;
                             }
                           break ;
                      }
                   case(0) :
                      {
                         //printf("%d already in the tree\n",item) ;
                         flag = 1 ;
                         return temp ;
                         break ;
                      }
                    case(-1) :
                      {
                          if( temp->llink == NULL )
                            {
                              /*tmp = (Tree)malloc(sizeof(*tmp)) ;
                              temp->llink = tmp ;
                              tmp->data = item ;
                              tmp->llink = tmp->rlink = NULL ;*/
                              flag = 1 ; return NULL ;
                            }
                           else
                            {
                              temp = temp->llink ;
                             }
                           break ;
                      }
                  }
              }
        }
 }
void in_order(Tree r)
 {
   if(r)
     {
        in_order(r->llink) ;
        printf("%d\t",r->data) ;
        in_order(r->rlink) ;
     }
 }
int main()
 {
   int f = 0 , choice , d ;
   Tree ptr ;
   while(f == 0 ) {
   printf("1 : insert 2 : search 3 : display 4 : exit \n") ;
   scanf("%d",&choice) ;
   switch(choice) {
         case(1) :
              scanf("%d",&d) ;
              insert(d) ;
              break ;
         case(2) :
              scanf("%d",&d) ;
              ptr= search(d) ;
              if(ptr) { printf( " %d found \n" , ptr->data) ; }
              else { printf(" %d not found \n" , d) ; }
              break ;
         case(3) :
              in_order(root) ;
              printf("\n") ;
              break ;
         case(4) : f = 1 ; break ;
     }
   }
 }
