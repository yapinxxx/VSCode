//uva12820
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, s, t, i, j, k;
    char c;

    s = 1;
    while (scanf("%d", &n) != EOF) //word number
    {
        getchar(); //get a char \n (enter) because the next function
                   //is scanf with %c , if not getchar() it will get
                   //the \n(enter)
        t = 0;
        while (n--) // control word number
        {
            int num[26] = {0}; //26 alphabet
            bool ans[30] = {};
            while (scanf("%c", &c) != EOF) //scanf input char it also can
                                           //read the \n(enter)
            {
                if (c == '\n')
                    break;
                num[c - 'a']++;
            }
            for (i = 0, j = 0, k = 0; i < 26; i++)
            {
                printf("i = %c num[i] = %d\n", i + 'a', num[i]);
                if (num[i]) // if alphabet >= 1
                {
                    j++; //different alphabet
                    printf("j = %d\n", j);
                    printf("alphabet %c  times %d hit %d\n", i + 'a', num[i], ans[num[i]]);
                    if (ans[num[i]]) // the same number of char
                    {
                        k = 1;
                        break;
                    }
                    ans[num[i]] = 1;
                }
            }
            if (k == 0 && j != 1) //don't have same times, different alphabet
                t++;              //more than 1 cool word ++
        }
        printf("Case %d: %d\n", s++, t);
    }
    return 0;
}