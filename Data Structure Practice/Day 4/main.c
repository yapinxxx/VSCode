
//UVA 12820: Cool Word 
#include <stdio.h>
#include <stdlib.h>
struct cool_word
{
    int count;
    char letter;
}typedef c_w;

int check(char *ary);
int cool(char *ary, int len);
int print_cool_word(c_w *word, int dif);


struct case_information
{
    int tag_num;
    int success_num;
}typedef case_i;


int main()
{
    int c_num, w_num, l_num,i,j,
        cool_count;

    char word[30];

    case_i Case[30];

    c_num = 0;//case number
    cool_count = 0;
    while(scanf("%d",&w_num)!=EOF)//words number
    {
        c_num++;
        Case[c_num].tag_num = c_num;
        for(j=0;j<w_num;j++)
        {
            scanf("%s",word);
            cool_count += check(word);  
            //printf("%s %d\n",word,cool_count);
        }
        Case[c_num].success_num = cool_count;
        cool_count = 0;
    }
    for(i=1;i<=c_num;i++)
    {
        printf("Case %d: %d\n",i,Case[i].success_num);
    }
    
    getchar();
    return 0;
}

int check(char *ary)
{
    int len,i,count,cool_state;
    count = 0;
    i = 0;
    //printf("%c\n",ary[3]);
    while(ary[i]!='\0')
    {
        count++;
        i++;
    }
    len = count;

    cool_state = cool(ary,len);

    //printf("%d\n",len);
    return cool_state;
}


int cool(char *ary, int len)
{
    int i,j,dif;
    c_w *word;
    dif = 0;
    word =(c_w*)malloc(sizeof(c_w)*len);
    for(i=0;i<len;i++)
    {
        word[i].letter = 0;
        word[i].count = 0;
    }

    for(i=0;i<len;i++)
    {
        for(j=0;j<=dif;j++)
        {
            if(dif>len)
            {
                printf("mistake\n");
                return 0;
            }
            //print_cool_word(word,dif);
            if(ary[i]==word[j].letter)
            {
                word[j].count++;
                break;
            }
            else if(j==(dif))
            {
                word[j].letter = ary[i];
                word[j].count = 1;
                dif++;
                break;
            }
        }
        //printf("%d\n",dif);
    }
    if(dif==1)
    {
        return 0;
    }
    //print_cool_word(word,dif);
    for(i=0;i<dif;i++)
    {
        for(j=i+1;j<dif;j++)
        {
            if(word[i].count==word[j].count)
            {
                return 0;
            }
        }
    }

    free(word);
    return 1;
}


int print_cool_word(c_w *word, int dif)
{
    int i;
    printf("dif %d\n",dif);
    for(i=0;i<dif;i++)
    {
        printf("letter=%c count=%d\n",word[i].letter,word[i].count);
    }
}