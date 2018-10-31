#include<stdio.h>

struct Student
{
    int age;
    float score;
    char sex;
}

int main()
{
    struct Student st = {80,66.6,'f'};

    (* &st).age = 88;

    printf("%d\n",st.age);
    return 0;
}