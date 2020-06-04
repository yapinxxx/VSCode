#include <stdio.h>
#include <stdlib.h>
//UVA 11677 Alarm Clock
int count_m(int H1, int M1, int H2, int M2);

int main()
{
    int H1, M1, H2, M2, ans;
    while (scanf("%d %d %d %d", &H1, &M1, &H2, &M2) != EOF)
    {
        if ((H1 + M1 + H2 + M2) == 0)
        {
            break;
        }
        ans = count_m(H1, M1, H2, M2);
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}

int count_m(int H1, int M1, int H2, int M2)
{
    int tmp1, tmp2;
    tmp2 = M2 - M1;

    if (tmp2 < 0)
    {
        tmp2 = 60 + tmp2;
        H2--;
    }
    tmp1 = H2 - H1;
    if (tmp1 < 0)
    {
        tmp1 = tmp1 + 24;
    }
    tmp1 = tmp1 * 60;
    tmp1 = tmp1 + tmp2;
    return tmp1;
}