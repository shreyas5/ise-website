#include<stdio.h>
#define QUEUE_SIZE 5
void insert_rear(int,int *,int []);
void delete_front(int *,int *,int []);
void display(int [],int,int);
int qempty(int ,int);
int qfull(int );
void main()
{
  int q[10],r=-1,f=0,ch,item;
  clrscr();
  for(;;)
  {
  printf("Press 1 for Insert \n 2 for Delete \n 3 for display\n");
  printf("Enter your choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
     case 1: printf("Enter the item to be inserted\n");
	     scanf("%d",&item);
	     insert_rear(item,&r,q);
	     break;
     case 2 : delete_front(&f,&r,q);
	     //printf("Item deleted=%d",item_deleted);
	     break;
     case 3 : display(q,f,r);
	      break;
    default : exit(0);
  }
}
  getch();
}
void insert_rear(int item,int *r, int q[])
{
   if(qfull(*r))
   {
     printf("Queue is full\n");
     return;
   }
    *r=*r+1;
    q[*r]=item;
}
void delete_front(int *f,int *r,int q[])
{
   int item_deleted;
   if(qempty(*f,*r))
   {
      printf("QUEUE is empty\n");
      return;
   }
   item_deleted=q[*f];
   *f=*f+1;
   if(*f>*r)
   {
     *f=0,*r=-1;
   }
   printf("Item deleted=%d\n", item_deleted);
}
void display(int q[],int f,int r)
{
 int i;
   if(qempty(f,r))
   {
      printf("QUEUE is empty\n");
      return;
   }
   printf("Content of the QUEUE is\n");
   for(i=f;i<=r;i++)
     printf("%d\n",q[i]);
}
int qfull(int r)
{
   return(r==QUEUE_SIZE-1)?1:0;
}
int qempty(int f,int r)
{
  return(f>r)?1:0;
}
