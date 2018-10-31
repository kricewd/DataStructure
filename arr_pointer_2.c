#include<stdio.h>

int main()
{
  // void f(int *,int);
  int a[5] = {1,2,3,4,5};
  printf("%p\n", a);
  printf("%p\n", &a[0]);
  int i = &a[4]-a;

  int *p  = a;
  printf("%d\n", i);

  printf("%ld\n", sizeof(p));
  return 0;
}

void f(int * arr,int len)
{
  return ;
}
