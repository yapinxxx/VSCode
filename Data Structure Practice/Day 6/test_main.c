#include <stdio.h>
#include <stdlib.h>
//ctrl + alt + n
#define size 100010
int my_strlen(char ary[size]);
int cmp_fun(char ary[size]);
int hit_fun(char test[3], int target[26][26][26]);

int main()
{
    int c, c_num, i, j, k, m, count, len;
    char ary[size];
    FILE *fin, *fout;
    fin = fopen("inputA", "r");
    fout = fopen("outputA", "w");
    if (fin == NULL || fout == NULL)
    {
        fprintf(fout, "Wrong Open\n");
        getchar();
    }
    count = 0;
    fscanf(fin, " %d", &c_num);
    for (i = 0; i < c_num; i++)
    {
        count = 0;
        fscanf(fin, "%s", ary); //scanf("%[^\n \t]")
        //printf("%s\n",ary);
        len = my_strlen(ary);
        //printf("len %d\n",len);
        count = cmp_fun(ary);
        fprintf(fout, "%d\n", count);
        for (j = 0; j < len; j++)
        {
            ary[i] = 0;
        }
    }
    fclose(fin);
    fclose(fout);
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
    for (i = 0; i < len - 2; i++)
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

int hit_fun(char test[3], int target[26][26][26])
{
    int i, j, k;
    if (target[test[0] - 'A'][test[1] - 'A'][test[2] - 'A'] == 0)
    {
        target[test[0] - 'A'][test[1] - 'A'][test[2] - 'A'] = 1;
        //printf("MISS\n");
        //printf("%c %c %c\n",test[0],test[1],test[2]);

        return 1;
    }
    else
    {

        //printf("HIT\n");
        //printf("%c %c %c\n",test[0],test[1],test[2]);
        return 0;
    }
}