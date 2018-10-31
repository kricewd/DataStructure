#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node * Next;
} Node;

typedef struct Node * LinkList;

typedef int Status;

#define OK 0;
#define ERROR 1;

void CreateList(LinkList *,int n);


int main()
{

    LinkList p;

    CreateList(&p,5);


    printf("########################\n");

    while(NULL!=p->Next)
    {
        printf("%d\n",p->Next->data);

        p = p->Next;
    }
}

//获取第i个节点的元素
Status GetElem(LinkList L,int i,ElemType * e)
{
    int j;

    LinkList p;

    j = 1;
    p = L->Next;

    while(p && j<i)
    {
        p = p->Next;

        ++j;
    } 

    if(!p||j>i)
    {
        return ERROR;
    }

    * e = p->data;

    return OK; 
}


//插入新的结点 
Status ListInsert(LinkList L,int i,ElemType * e)
{
    int j;

    LinkList p,s;

    p = L;
    j = 1;

    while(p && j< i-1)
    {
        p = p->Next;
        j++;
    }

    if(!p||j>i-1   )
    {
        return ERROR;
    }

    s = (LinkList) malloc (sizeof(Node));

    s->data = * e;

    s->Next = p->Next;

    p->Next = s;


    return OK;

}

Status ListDelete(LinkList L,int i,ElemType *e)
{
    LinkList p,q;
    int j;

    p = L;
    j = 0;

    while(p->Next && j<i-1)
    {
        p = p->Next;

        ++j;
    }

    if(!(p->Next) || j>i)
    {
        return ERROR;
    }

    q = p->Next;//要删除的结点

    p->Next = q->Next;//将要删除结点后面第一个结点赋值 给删除结点前一个结点的指针域 

    free(q);

    *e = q->data; 
    
    return OK;
  
}

//创建链表
//变量跨函数使用，函数的参数必须传变量的地址即指针
void CreateList(LinkList * L,int n)
{   
    int i = 0;

    LinkList p;

    * L = (LinkList)malloc(sizeof(Node));

    (* L)->Next = NULL;

    for(i; i<n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));

        printf("第%d个元素：\n",i+1);

        scanf("%d",&p->data);

        p->Next = (* L)->Next;

        (*L)->Next = p;
    }

    // return L;
}

//清除整个链表
Status clearList(LinkList * L)
{
    LinkList p,q;

    p = (*L)->Next;

    while(p)
    {
        q = p->Next;

        free(p);

        p = q->Next;
    }

    (*L)->Next = NULL;

    return ok;

}