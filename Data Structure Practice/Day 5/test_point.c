#include <stdio.h>
#include <stdlib.h>
int test_fun(int *m, int *n, int x);

int main()
{
    int m,n,x;
    scanf(" %d %d %d",&m,&n,&x);

    test_fun(&m,&n,x);
    printf("%d %d %d \n",m,n,x);
    fflush(stdin);
    getchar();
    return 0;

}

int test_fun(int *m, int *n, int x)
{
    *m = *m + x;
    *n = x;
    x = -1;
}