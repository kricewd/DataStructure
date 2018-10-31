# include<stdio.h>

void swap(int a,int b)
{
    int t;
    
    t = a;
    a = b;
    b = t;
    return;
}

void swap2(int * p, int * q)
{
    int * t;

    t = p;
    p = q;
    q = t;
    return;
}


void swap3(int * p,int * q)
{
    int t;

    t = * p;
    * p = * q;
    * q = t;
    return;
}

int main()
{
    int a = 3;
    int b = 5;

    // swap(a,b);  //a=3,b=5;

    // swap2(&a,&b); //a=3,b=5;

    swap3(&a,&b);
    
    printf("a=%d,b=%d\n",a,b);

    return 0;

}

