#include<stdio.h>
#include<stdlib.h>
#define capacity 3

void insertQ(int);
void deleteQ();
void display();

int *cQueue;
int front = -1, rear = -1;

void main()
{
   int choice, value;
   cQueue = (int *)malloc(sizeof(int) * capacity);
   while(1){
      printf("\n****** MENU ******\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("\nEnter the value to be insert:  ");
		 scanf("%d",&value);
		 insertQ(value);
		 break;
	 case 2: deleteQ();
		 break;
	 case 3: display();
		 break;
	 case 4: exit(0);
	 default: printf("\nPlease select the correct choice!!!\n");
      }
   }
}
void insertQ(int value)
{
   if((front == 0 && rear == capacity - 1) || (front == rear+1))
      printf("\nCircular Queue is Full! Insertion not possible!!!\n");
   else{
      if(rear == capacity-1 && front != 0)
	 rear = -1;
	
      cQueue[++rear] = value;
      if(front == -1)
	 front = 0;
   }
}
void deleteQ()
{
   if(front == -1 && rear == -1)
      printf("\nCircular Queue is Empty! Deletion is not possible!!!\n");
   else{
      printf("\nDeleted element : %d\n",cQueue[front++]);
	
      if(front == capacity)
	 front = 0;
      if(front-1 == rear)
	 front = rear = -1;
   }
}
void display()
{
   if(front == -1)
      printf("\nCircular Queue is Empty!!!\n");
   else{
      int i = front;
      printf("\nCircular Queue Elements are : \n");
      if(front <= rear){
	 while(i <= rear)
	    printf("%d\t",cQueue[i++]);
      }
      else{
	 while(i <= capacity - 1)
	    printf("%d\t", cQueue[i++]);
	 i = 0;
	 while(i <= rear)
	    printf("%d\t",cQueue[i++]);
      }
   }
}
