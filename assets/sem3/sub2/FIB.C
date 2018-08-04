#include<stdio.h>
int fact(int n)
{
  if(n==0) return 1;
  return n*fact(n-1);
}
void main()
{
  int n,res=0;
  clrscr();
  printf("Enter the value of N\n");
  scanf("%d",&n);
  res=fact(n);
  printf("Fact(%d)=%d",n,res);
  getch();
}
