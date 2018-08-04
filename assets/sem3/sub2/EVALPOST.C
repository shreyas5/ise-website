#include<stdio.h>
#include<math.h>
#include<string.h>
double op(char symbol,double op1,double op2)
{
  switch(symbol)
    {
      case '+' : return op1+op2;
      case '-' : return op1-op2;
      case '*' : return op1*op2;
      case '/' : return op1/op2;
      case '$' :
      case '^' : return pow(op1,op2);
    }
}
void push(double item,int *top,double s[])
{
  *top=*top+1;
  s[*top]=item;
}
double pop(int *top,double s[])
{
  double item;
  item=s[*top];
  *top=*top-1;
  return item;
}
int isdigit(char symbol)
{
  return (symbol>='0' && symbol<='9');
}
void main()
{
 double s[20];
 double res,op1,op2;
 int top,i;
 char postfix[20];
 char symbol;
 clrscr();
 printf("Enter the postfix expression\n");
 scanf("%s",postfix);
 top=-1;
 for(i=0;i<strlen(postfix);i++)
 {
    symbol=postfix[i];
    if(isdigit(symbol))
      push(symbol-'0',&top,s);
    else
    {
       op2=pop(&top,s);
       op1=pop(&top,s);
       res=op(symbol,op1,op2);
       push(res,&top,s);
    }
 }
 res=pop(&top,s);
 printf("result=%f\n",res);
 getch();
}
