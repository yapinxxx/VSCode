//UVA 13257
#include <stdio.h>
#include <stdlib.h>
//ctrl + alt + n
#define size 100010 //if the size too long, \
                    //we have to use FILE to check the answer
int my_strlen(char ary[size]);
int cmp_fun(char ary[size]);

int main()
{
    int c, c_num, i, j, k, m, count, len;
    char ary[size];
    count = 0;
    scanf(" %d", &c_num);
    for (i = 0; i < c_num; i++)
    {
        count = 0;
        scanf("%s", ary); //scanf("%[^\n \t]")
        //printf("%s\n",ary);
        len = my_strlen(ary);
        //printf("len %d\n",len);
        count = cmp_fun(ary);
        printf("%d\n", count);
        for (j = 0; j < len; j++) //initial ary
        {
            ary[i] = 0;
        }
    }

    while ((c = getchar()) != '\n' && c != EOF)
        ;
    getchar();
    return 0;
}

int my_strlen(char ary[size])
{
    int i, len;
    i = 0;
    while (ary[i] != '\0')
    {
        i++;
    }
    len = i;
    return len;
}

int cmp_fun(char ary[size])
{
    int i, j, k, len, tmpA, tmpB, tmpC, count, times,
        cmp[26][26][26] = {0},
        fst_hit[26], sec_hit[26], third_hit[26];
    char resize_ary[3] = {0};
    count = 0;
    len = my_strlen(ary);
    for (i = 0; i < 26; i++) //initial
    {
        fst_hit[i] = 0;
    }
    //printf("test\n");
    //printf("len %d\n",len);
    times = 0;
    for (i = 0; i < len - 2; i++) //if the times too many, the program will error
                                  //so we have to design a suitable rule
    {
        if (fst_hit[ary[i] - 'A'] == 1)
        {
            continue;
        }
        else
        {
            fst_hit[ary[i] - 'A'] = 1;
        }
        for (j = 0; j < 26; j++) //clear
        {
            sec_hit[j] = 0;
        }

        for (j = i + 1; j < len - 1; j++)
        {
            if (sec_hit[ary[j] - 'A'] == 1)
            {
                continue;
            }
            else
            {
                sec_hit[ary[j] - 'A'] = 1;
            }

            for (k = 0; k < 26; k++) //clear
            {
                third_hit[k] = 0;
            }

            for (k = j + 1; k < len; k++)
            {
                if (third_hit[ary[k] - 'A'] == 1)
                {
                    continue;
                }
                else
                {
                    third_hit[ary[k] - 'A'] = 1;
                }

                // tmpA = ary[i];
                // tmpB = ary[j];
                // tmpC = ary[k];

                // resize_ary[0] = tmpA;
                // resize_ary[1] = tmpB;
                // resize_ary[2] = tmpC;
                //printf("%s\n",resize_ary);
                times++;
                //count = count + hit_fun(resize_ary,cmp);
            }
        }
    }
    //printf("%d\n",times);

    return times;
}
