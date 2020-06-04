#include <stdio.h>
#include <stdlib.h>
//UVA 11417
int GCD(int a, int b);

int main()
{
    int i, j, G, N, gcd;
    G = 0;
    while (scanf("%d", &N) != EOF)
    {
        if (N == 0)
        {
            break;
        }
        for (i = 1; i < N; i++)
        {
            for (j = i + 1; j <= N; j++)
            {
                G += GCD(i, j);
                //printf("%d\n", G);
            }
        }
        printf("%d\n", G);
        G = 0;
    }

    system("pause");
    return 0;
}

int GCD(int a, int b)
{
    int tmp1, tmp2, g;
    tmp1 = a;
    tmp2 = b;
    //printf("%d %d\n", a, b);
    while (1)
    {
        if (a > b)
        {
            tmp1 = a % b;
            a = a % b;
            if (a == 0)
            {
                //printf("tmp2 %d\n", tmp2);
                return tmp2;
            }
        }
        else if (a < b)
        {
            tmp2 = b % a;
            b = b % a;
            if (b == 0)
            {
                //printf("tmp1 %d\n", tmp1);
                return tmp1;
            }
        }
        else
        {
            //printf("a %d\n", a);
            return a;
        }
    }
    //printf("%d\n", tmp);

    return 1;
}
