/*10010: Where's Waldorf?*/
#include <stdio.h>
#include <stdlib.h>
/*#define EOF -1*/

int print_ary2(char ary[51][51],int m, int n);
int my_strlen(char word[51]);
int my_tolower(char ary[51]);
int find_start(char grid[51][51],int size_row,int size_col,char first, int *start_row, int *start_col);
int active(char map[51][51], char target[21],
            int now_row, int now_col,
            int direction, int hit);

int main()
{
    int i,j,k,c_num,m,n,w_num,x,y,got_word,start_row,start_col,
        ans[21][3];
    char grid[51][51]={},t_word[21][51]={},c;
    
    x=0;
    y=0;
    start_row = 0;
    start_col = 0;
    scanf(" %d",&c_num);
    for(i=0;i<c_num;i++)
    {
        scanf(" %d %d",&m,&n);

        for(j=0;j<m;j++)
        {
            for(k=0;k<n;k++)
            {
                scanf(" %c",&grid[j][k]);

            }

        }

        scanf("%d",&w_num);
        for(j=0;j<w_num;j++)
        {
            scanf("%s",t_word[j]);
        }

        for(j=0;j<m;j++)
        {
            my_tolower(grid[j]);
            
        }
        for(j=0;j<w_num;j++)
        {
            my_tolower(t_word[j]);
        }

        for(j=0;j<w_num;j++)
        {
            start_row = 0;
            start_col = 0;
            k=0;
            got_word = 0;


            find_start(grid,m,n,t_word[j][0],&start_row,&start_col);

            while (got_word!=1)
            {

                got_word = active(grid,t_word[j],start_row,start_col,k,1);
                if(got_word!=1)
                {
                    if(k==7)
                    {
                        if(start_col+1<n)
                        {
                            start_col++;
                        }
                        else
                        {
                            start_row++;
                            start_col = 0;
                        }
                        
                        find_start(grid,m,n,t_word[j][0],&start_row,&start_col);

                        k = 0;
                        continue;
                    }
                    k++;
                }

            }
            ans[j][0] = my_strlen(t_word[j]);
            ans[j][1] = start_row+1;
            ans[j][2] = start_col+1;

        }

        for(j=0;j<w_num;j++)
        {
            printf("%d %d\n",ans[j][1],ans[j][2]);
        }
        if(i!=c_num-1)
        {
            printf("\n");
        }
        
        

    }
    while((c=getchar())!='\n' && c!=EOF);
    getchar();
    return 0;

}

int my_strlen(char word[51])
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

int find_start(char grid[51][51],int size_row,int size_col,char first, int *start_row, int *start_col)
{
    int i,j,times;
    times = 0;
    if(*start_col!=0)
    {
        times = 1;
    }
    for(i=*start_row;i<size_row;i++)
    {
        for(j=0;j<size_col;j++)
        {
            if(times==1)
            {
                j = *start_col;
                times = 0;
            }
            if(grid[i][j]==first)
            {

                *start_row = i;
                *start_col = j;
                return 1;
            }
        }
    }
    printf("error find\n");
    char c;
    while((c=getchar())!='\n'&&c!=EOF);
    getchar();
    return 0;
}

int my_tolower(char ary[51])
{
    int i,len;
    char *l_ary;
    len = my_strlen(ary);
    for(i=0;i<len;i++)
    {
        if(ary[i]<'a')
        {
            ary[i] = ary[i]-'A'+'a';
        }
    }
    return 0;
}


int active(char map[51][51], char target[21],
            int now_row, int now_col,
            int direction, int hit)
{
    int len,i,j,tmp_hit;
    len = my_strlen(target);
    tmp_hit = hit;
    
    if(hit==len)
    {
        
        return 1;
    }


    switch (direction)
        {
            
            case 0:
                if(target[hit] == map[now_row-1][now_col])
                {
                    return active(map,target,now_row-1,now_col,0,hit+1);
                }
                else
                {
                    
                    return 0;   
                }
                break;
            
            case 1:
                if(target[hit] == map[now_row-1][now_col+1])
                {
                    return active(map,target,now_row-1,now_col+1,1,hit+1);
                }
                else
                {
                    
                    return 0;   
                }
                break;

            case 2:
                if(target[hit] == map[now_row][now_col+1])
                {
                    return active(map,target,now_row,now_col+1,2,hit+1);
                }
                else
                {
                    
                    return 0;   
                }
                break;

            case 3:
                if(target[hit] == map[now_row+1][now_col+1])
                {
                    return active(map,target,now_row+1,now_col+1,3,hit+1);
                }
                else
                {
                    
                    return 0;   
                }
                break;
            
            case 4:
                if(target[hit] == map[now_row+1][now_col])
                {
                    return active(map,target,now_row+1,now_col,4,hit+1);
                }
                else
                {
                    
                    return 0;   
                }
                break;
            
            case 5: 
                if(target[hit] == map[now_row+1][now_col-1])
                {
                    return active(map,target,now_row+1,now_col-1,5,hit+1);
                }
                else
                {
                    
                    return 0;   
                }
                break;

            case 6:
                if(target[hit] == map[now_row][now_col-1])
                {
                    return active(map,target,now_row,now_col-1,6,hit+1);
                }
                else
                {
                    return 0;   
                }
                break;

            case 7: 
                if(target[hit] == map[now_row-1][now_col-1])
                {
                    return active(map,target,now_row-1,now_col-1,7,hit+1);
                }
                else
                {
                    return 0;   
                }
                break;

            default:
                break;
        }


    return 0;
}

