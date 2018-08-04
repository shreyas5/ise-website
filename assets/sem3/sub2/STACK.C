#include<stdio.h>
#define STACK_SIZE 5
void push(int,int *,int []);
int pop(int *,int []);
void display(int,int []);
void main()
{
  int s[10],top=-1,ch,item,item_deleted;
  clrscr();
  for(;;)
  {
  printf("Press 1 for push \n 2 for pop \n 3 for display\n");
  printf("Enter your choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
     case 1: printf("Enter the item to be inserted\n");
	     scanf("%d",&item);
	     push(item,&top,s);
	     break;
     case 2 : item_deleted=pop(&top,s);
	     printf("Item deleted=%d",item_deleted);
	     break;
     case 3 : display(top,s);
	      break;
    default : exit(0);
  }
}
  getch();
}
void push(int item,int *top, int s[])
{
   if(*top==STACK_SIZE-1)
   {
     printf("Stack is full\n");
     return;
   }
    *top=*top+1;
    s[*top]=item;
}
int pop(int *top,int s[])
{
   int item_deleted;
   if(*top==-1)
   {
      printf("Stack is empty\n");
      return;
   }
   item_deleted=s[*top];
   *top=*top-1;
   return item_deleted;
}
void display(int top,int s[])
{
 int i;
   if(top==-1)
   {
      printf("Stack is empty\n");
      return;
   }
   printf("Content of the Stack is\n");
   for(i=0;i<=top;i++)
     printf("%d\n",s[i]);
}