//10010: Where's Waldorf?
#include<stdio.h>
#include<stdlib.h>

//#define EOF -1
int print_ary2(char ary[][50],int m, int n);
int my_strlen(char *word);
int my_tolower(char *ary);
int find_start(char grid[][50],int size_row,int size_col,char first, int *start_row, int *start_col);
int active(char map[][50], char *target,
            int now_row, int now_col,
            int direction, int hit);

int main()
{
    int i,j,k,c_num,m,n,w_num,x,y,got_word,start_row,start_col,
        ans[20][3];
    char grid[50][50]={},t_word[20][51]={};
    FILE *fin,*fout;
    fin = fopen("inputB.txt","rt");
    fout = fopen("outputB.txt","w+t");
    x = 0;
    y = 0;  
    start_row = 0;
    start_col = 0;
    fscanf(fin," %d",&c_num);
    for(i=0;i<c_num;i++)
    {
        fscanf(fin," %d %d",&m,&n);//size row col
        for(j=0;j<m;j++)
        {
            for(k=0;k<n;k++)
            {
                fscanf(fin," %c",&grid[j][k]);
            }
            
        }
        //print_ary(grid,m,n);
        fscanf(fin,"%d",&w_num);
        for(j=0;j<w_num;j++)
        {
            fscanf(fin,"%s",t_word[j]);
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
            //printf("%s\n",t_word[j]);

            find_start(grid,m,n,t_word[j][0],&start_row,&start_col);
            //printf("start %d %d\n",start_row+1,start_col+1);
            while (got_word!=1)
            {
                //printf("k %d\n",k);
                got_word = active(grid,t_word[j],start_row,start_col,k,1);
                if(got_word!=1)
                {
                    if(k==7)
                    {
                        // printf("wrong start\n");
                        // printf("start %d %d\n",start_row+1,start_col+1);
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
                        // printf("new start %d %d %c\n",start_row+1,start_col+1,grid[start_row][start_col]);
                        k = 0;
                        continue;
                    }
                    k++;
                }
                //printf("got_word %d\n",got_word);   
            }
            ans[j][0] = my_strlen(t_word[j]);
            ans[j][1] = start_row+1;
            ans[j][2] = start_col+1;
            //printf("%d %d\n",ans[j][1],ans[j][2]);
        }

        for(j=0;j<w_num;j++)
        {
            fprintf(fout,"%d %d\n",ans[j][1],ans[j][2]);
        }
        if(i!=c_num-1)
        {
            fprintf(fout,"\n");
        }
        
        

    }
    fclose(fin);
    fclose(fout);
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
    getchar();
    return 0;

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

int find_start(char grid[][50],int size_row,int size_col,char first, int *start_row, int *start_col)
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
                //printf("target word '%c'\n",first);
                *start_row = i;
                *start_col = j;
                return 1;
            }
        }
    }
    printf("error find\n");
    getchar();
    return 0;
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
    //printf("%s\n",ary);
    return 0;
}


int active(char map[][50], char *target,
            int now_row, int now_col,
            int direction, int hit)
{
    int len,i,j,tmp_hit;
    len = my_strlen(target);
    tmp_hit = hit;

    if(hit==len)
    {
        //printf("%d %d\n",hit,len);
        //printf("get word\n");
        return 1;
    }


    switch (direction)
        {
            
            case 0://north
                if(target[hit] == map[now_row-1][now_col])
                {
                    return active(map,target,now_row-1,now_col,0,hit+1);
                }
                else
                {
                    //printf("wrong direction\n");
                    return 0;   
                }
                break;
            
            case 1://north east
                if(target[hit] == map[now_row-1][now_col+1])
                {
                    return active(map,target,now_row-1,now_col+1,1,hit+1);
                }
                else
                {
                    //printf("wrong direction\n");
                    return 0;   
                }
                break;

            case 2://east
                if(target[hit] == map[now_row][now_col+1])
                {
                    return active(map,target,now_row,now_col+1,2,hit+1);
                }
                else
                {
                    // printf("wrong direction\n");
                    return 0;   
                }
                break;

            case 3://south east
                if(target[hit] == map[now_row+1][now_col+1])
                {
                    return active(map,target,now_row+1,now_col+1,3,hit+1);
                }
                else
                {
                    // printf("wrong direction\n");
                    return 0;   
                }
                break;
            
            case 4://south
                if(target[hit] == map[now_row+1][now_col])
                {
                    return active(map,target,now_row+1,now_col,4,hit+1);
                }
                else
                {
                    // printf("wrong direction\n");
                    return 0;   
                }
                break;
            
            case 5: //south west
                if(target[hit] == map[now_row+1][now_col-1])
                {
                    return active(map,target,now_row+1,now_col-1,5,hit+1);
                }
                else
                {
                    // printf("wrong direction\n");
                    return 0;   
                }
                break;

            case 6: //west
                if(target[hit] == map[now_row][now_col-1])
                {
                    return active(map,target,now_row,now_col-1,6,hit+1);
                }
                else
                {
                    // printf("wrong direction\n");
                    return 0;   
                }
                break;

            case 7: //north west
                if(target[hit] == map[now_row-1][now_col-1])
                {
                    return active(map,target,now_row-1,now_col-1,7,hit+1);
                }
                else
                {
                    // printf("wrong direction\n");
                    return 0;   
                }
                break;

            default:
                break;
        }

    return 0;

}



int print_ary2(char ary[][50],int m, int n)
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
    return 0;
}
