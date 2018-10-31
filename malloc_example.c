#include <stdio.h>
#include <malloc.h>

int main()
{
  int i = 5;// 分配了4个字节，静态分配

  int j;
  int len;

  printf("输入要存元素的个数:");

  scanf("%d",&len);

  int * p = (int *) malloc(4*len);
    /**
      1、要使用malloc函数，必须添加malloc.h这个头文件
      2、malloc函数只有一个形参，并且形参是整数
      3、4表示请求系统为本程序分配4个字节
      4、malloc函数只能返回第一个字节的地址
      5、 8行总共分配了12个字节，p占 8个字节（64位），p指向的内存也占4个字节
      6、p本身所占的内存是静态分配的，p所指向的内存是动态分配的
    */


  for(j=0;j<len;++j)
  {
     scanf("%d",&p[j]);
  }

  printf("##############################\n");

  for(j=0;j<len;j++)
  {
    printf("%d\n",p[j]);
  }

  free(p);
  
  return 0;

}
