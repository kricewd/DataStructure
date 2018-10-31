#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Node
{
    int data; //数据域
    struct Node * pNext;//指针域
};

//函数申明
struct Node * create_list();
void traverse_list(struct Node *);


int main(void)
{
    struct Node * pHead = NULL;//存放头节点的地址，即头指针

    pHead  = create_list();//创建一个非循环的单链表，并将该链表的头结点赋值的头指针

    traverse_list(pHead);//遍历链表

    return 0;
}

/**
 *
 * 创建一个链表
 **/
struct Node * create_list()
{
    int len;//用来存放有效节点的个数
    int i;
    int val;//用来临时存放用户输入的结点的值

    //分配一个不存放有效数据的头结点
    struct Node * pHead = (struct Node *) malloc(sizeof(struct Node));

    if(NULL == pHead)
    {
        printf("分配动态内存失败！\n");
        exit(-1);
    }


    struct Node * pTail = pHead;

    pTail->pNext = NULL;

    printf("请输入需要生成的链表结点的个数:len=");

    scanf("%d",&len);

    for(i = 0;i<len;++i)
    {
        printf("请输入第%d个结点的值：",i+1);

        scanf("%d",&val); 

        struct Node * pNew = (struct Node * )malloc(sizeof(struct Node));

         if(NULL == pNew)
        {
            printf("分配动态内存失败！\n");
            exit(-1);
        }

        pNew->data = val;//给单个结点的数据域赋值

        pTail->pNext = pNew; //将

        pNew->pNext = NULL;

        pTail = pNew;
    }
    return pHead;

}
/**
 * 遍历一个链表
 * 
 **/
void traverse_list(struct Node * pHead)
{
    struct Node * p;

    p = pHead->pNext;//p是头结点，pHead是头指针

    while(NULL!=p)
    {
        printf("%d\n",p->data);

        p = p->pNext;
    }

    // while(NULL!=pHead->pNext)
    // {
    //     printf("%d\n",pHead->pNext->data);

    //     pHead = pHead->pNext;
    // }
    return ;
}

