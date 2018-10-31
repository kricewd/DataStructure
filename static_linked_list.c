#include <stdio.h>

#define MAXSIZE 10
#define OK 0;
#define ERROR 1;

typedef char ElemType;

typedef int Status;

// typedef

Status InitList(StaticLinkList); //Statement  function

typedef struct{
    ElemType data; //defineed member column

    int cur;    //defined cursor
} Component,StaticLinkList[MAXSIZE];


void main(/* arguments */) {

}


/**
* createed a static linked list of empty
*
**/
Status InitList(StaticLinkList * space)
{
  int i;

  for(i = 0; i<MAXSIZE-1;i++){
    *space[i].cur = i+1;
  }

  *spac[MAXSIZE-1].cur = 0;

  return OK;
}

int Malloc_SL(StaticLinkList * spac ){

  /*if spare space linked list is empty,
  *then return distribution node subscript,
  *otherwise return 0
  */
  int i = space[0].cur;

  if(i){
    space[0].cur = space[i].cur;
  }

  return i;
}


Status InsertList(StaticLinkList * space,int i,ElemType e)
{
  int j,k,l;

  k = MAXSIZE  -1;//last element of the array

  if(i<1 || i>ListLength(L)+1){

    return ERROR;
  }

  j = Malloc_SL(L);

  if(j){
    L[j].data = e;
    for(l = 1;l <=i-1; l++){
      k = L[k].cur;
    }
    L[j].cur = L[k].cur;
    L[k].cur = j;

    return ok;
  }

  return ERROR;
}
