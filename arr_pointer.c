#include <stdio.h>

int main()
{
  void f(int *,int len);

  int a[5] = {1,2,3,4,5};

  f(a,5);

  return 0;
}

void f(int * arr,int len)
{
  int i;

  for(i=0;i<len;++i){
    printf("%d\n", *(arr+i));
  }
}
