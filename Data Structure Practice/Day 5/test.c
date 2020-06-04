#include <stdio.h>
#include <stdlib.h>
int print_ary(char ary[][50],int m, int n);
int my_strlen(char *word);
int my_tolower(char *ary);
int main()
{
    int i,j,k,c_num,m,n,w_num,x,y;
    char grid[50][50]={},t_word[20][50]={};
    x=0;
    y=0;
    scanf(" %d",&c_num);
    for(i=0;i<c_num;i++)
    {
        scanf(" %d %d",&m,&n);
        //printf("%d %d\n",m,n);
        for(j=0;j<m;j++)
        {
            for(k=0;k<n;k++)
            {
                scanf(" %c",&grid[j][k]);
                //printf("%c",grid[j][k]);
            }
            //printf("\n");
            //getchar();
        }
        //print_ary(grid,m,n);
        scanf("%d",&w_num);
        for(j=0;j<w_num;j++)
        {
            scanf("%s",t_word[j]);
        }

        /*tolower*/
        for(j=0;j<m;j++)
        {
            my_tolower(grid[j]);
            
        }
        for(j=0;j<w_num;j++)
        {
            my_tolower(t_word[j]);
        }
        /*end*/

        /*print_ary(grid,m,n);
        for(j=0;j<w_num;j++)
        {
            printf("%s\n",t_word[j]);
        }*/
        


        
        

    }
    fflush(stdin);
    getchar();
    return 0;

}

int print_ary(char ary[][50],int m, int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%c",ary[i][j]);
        }
        printf("\n");
    }
}


int my_tolower(char *ary)
{
    int i,len;
    char *l_ary;
    len = my_strlen(ary);
    for(i=0;i<len;i++)
    {
        if(ary[i]<'a')//if the big alphabet
        {
            ary[i] = ary[i]-'A'+'a';
        }
    }
    printf("%s\n",ary);
}


int my_strlen(char *word)
{
    int i,j,len;
    i=0;
    while(word[i]!='\0')
    {
        i++;
    }
    len = i;
    return len;
}