#include<stdio.h>
#include<conio.h>
#include<string.h>
#define STACK_SIZE 20

void push(char,int *,char []);
char pop(int *,char []);
void infix_postfix(char [],char []);
void main()
{
  char infix[20],postfix[20];
  clrscr();
  printf("Enter a valid infix expression\n");
  scanf("%s",infix);
  infix_postfix(infix,postfix);
  printf("The postfix expression is\n");
  printf("%s\n",postfix);
  getch();
}
void infix_postfix(char infix[],char postfix[])
{
  int top,j,i;
  char s[30];
  char symbol;
  top=-1;
  push('#',&top,s);
  j=0;
  strrev(infix);
  for(i=0;i<strlen(infix);i++)
  {
     symbol=infix[i];
     while(F(s[top])>G(symbol))
     {
	postfix[j]=pop(&top,s);
	j++;
      }
      if(F(s[top]) !=G(symbol))
	 push(symbol,&top,s);
      else
	 pop(&top,s);
  }
  while(s[top]!='#')
  {
    postfix[j++]=pop(&top,s);
  }
  postfix[j]='\0';
  strrev(postfix);
}
void push(char item,int *top,char s[])
{
if(*top==STACK_SIZE-1)
{
printf("stack is full");
return;
}
*top=*top+1;
s[*top]=item;
}
char pop(int *top,char s[])
{
char item_deleted;
if(*top==-1)
{
return 0;
}
item_deleted=s[*top];
*top=*top-1;
return item_deleted;
}
int G(char symbol)
{
  switch(symbol)
  {
     case '+' :
     case '-' : return 1;
     case '*' :
     case '/' : return 3;
     case '^' :
     case '$' : return 6;
     case '(' :return 9;
     case ')' :return 0;
     default : return 7;
  }
}
int F(char symbol)
{
  switch(symbol)
  {
     case '+':
     case '-': return 2;
     case '*':
     case '/': return 4;
     case '^':
     case '$': return 5;
     case '(': return 0;
     case '#':return -1;
     default:return 8;
  }
}