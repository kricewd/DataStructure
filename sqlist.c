#include <stdio.h>
#include <stdlib.h>

# define LIST_INIT_SIZE 10 //线性表初始化存储空间大小
# define LISTINCREMENT 5  //线性表扩容增量

typedef int  ElemType;

struct  Sqlist {

    int lenght;     //当前线性表的长度

    int listsize;   //当前分配的存储空间（以siezeof(int)）

    ElemType * elem;
};

int InitList_Sq(struct Sqlist *); //函数声明

int ListInsert_Sq(struct Sqlist * ,int ,ElemType);//函数声明

int ListDelete_Sq(struct Sqlist * ,int , ElemType *);//函数声明

int main()
{

    int i = 0;
    int j = 0;
    struct Sqlist * list = (struct Sqlist *)malloc(sizeof(struct Sqlist *));

    InitList_Sq(list);

    ListInsert_Sq(list,2,10);

    for(;i<list->elem;i++)
    {
        printf("%d\n",list->elem[i]);
    }

    printf("#####################\n");

    ListDelete_Sq(list,2,2);

    for(;j<list->lenght;j++)
    {
        printf("%d\n",list->elem[j]);
    }

    // int a[2]  = {1,3};

    // int * p;

    // p = a;

    // printf("%d",p[0]);


    return 0;

}

//创建一个空的线性表
int InitList_Sq(struct Sqlist * L){

    struct Sqlist * list = L;

    int i;

    int num;

    /**
     * 创建一个空的线性表
     * 
     **/
    list->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));

    if(!list->elem){

        printf("分配空间失败！");

        return 1;
    }

    for(i=0;i<6;i++)
    {
        printf("输入第%d个元素:",i+1);
        scanf("%d",&num);
        list->elem[i] = num;
    }

    list->lenght = i;

    list->listsize = LIST_INIT_SIZE;

    return 0;
}

/**
 * 线性表插入元素 
 * 
 **/
int ListInsert_Sq(struct Sqlist * L,int i,ElemType e){
    
    //在顺序线性表L中第i个位置之前插入新的元素e
    if( i<1 || i>L->lenght+1 )
    {
        printf("超出边界!\n");

        exit(-1);
    }

    if(i <= L->lenght )//如果插入数据位置不在表尾
    {
        //将要插入位置后数据元素向后移动一位,
        //比如在数组下标为4的位置插入元素，
        //则将下标大于4的元素向后移动，最先移动最末尾元素
        for(int k = L->lenght-1; k >= i-1; k--)
        {
            L->elem[k+1] = L->elem[k];
        }
    }

    L->elem[i-1] = e; //将元素插入

    L->lenght++;

    return 0;
}


/**
 * 删除指定下标元素
 * 
 **/
int ListDelete_Sq(struct Sqlist * L,int i,ElemType * e)
{
    if(i<1 || (i > L->lenght)){

        return 1;
    }

    ElemType * p = &L->elem[i-1];//p为被删除元素的地址

    * e = * p; //删除的元素

    ElemType * q = L->elem + L->lenght -1; //表尾元素的位置

    for(++p; p<=q; ++p){

        * (p-1) = * p; //将删除位置之后的位置的元素向左移
    }

    --L->lenght;
    return 0;
}