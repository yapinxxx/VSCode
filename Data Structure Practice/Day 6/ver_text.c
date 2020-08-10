#include <stdio.h>
#include <stdlib.h>
//ctrl + alt + n
#define size 100010
int my_strlen(char ary[size]);
int cmp_fun(char ary[size]);
int hit_fun(char test[3],char target[26][26][26]);
int fprint_sort(char ary[3]);


int main()
{
    int c,c_num,i,j,k,m,count,len;
    char ary[size],cmp[26][26][26];
    FILE *fin,*fout;
    fin = fopen("inputA","r");
    fout = fopen("outputA","w");
    if(fin==NULL||fout==NULL)
    {
        fprintf(fout,"Wrong Open\n");
        getchar();
    }
	count = 0;
	fscanf(fin," %d",&c_num);
    printf("%d\n",c_num);
    fclose(fout);
    for(i=0;i<c_num;i++)
    {
        fout = fopen("outputA","a");
        printf("case %d\n",i);
        count = 0;
        fscanf(fin,"%s",ary);//scanf("%[^\n \t]")
        fprintf(fout,"%s\n",ary);
        len = my_strlen(ary);
        fprintf(fout,"len %d\n",len);
        fclose(fout);

        count = cmp_fun(ary);

        fout = fopen("outputA","a");
        fprintf(fout,"count %d\n",count);
        fclose(fout);
        
        for(j=0;j<len;j++)
        {
            ary[i] = 0;
        }
        
    }

    fout = fopen("outputA","a");
    fprintf(fout,"END\n");
	fclose(fin);
    fclose(fout);
    while((c=getchar())!='\n' && c!=EOF);
    getchar();
    
    return 0;

}



int my_strlen(char ary[size])
{
    int i,len;
    i = 0;
    while(ary[i]!='\0')
    {
        i++;
    }
    len = i;
    return len;
}

int cmp_fun(char ary[size])
{
    int i,j,k,len,tmpA,tmpB,tmpC,count,times,first_hit[26],
        cmp[26][26][26]={0},sec_hit[26],third_hit[26];
    char resize_ary[4]={0};//
    count = 0;
    len = my_strlen(ary);
    for(i=0;i<26;i++)
    {
        first_hit[i] = 0;
    }
    //printf("test\n");
    //printf("len %d\n",len);
    times = 0;
    for(i=0;i<len-2;i++)
    {
        for(j=0;j<26;j++)
        {
            sec_hit[j] = 0;
        }
        
        if(first_hit[ary[i]-'A']==1)
        {
            continue;
        }
        else
        {
            first_hit[ary[i]-'A'] = 1;
        }
        
        
        for(j=i+1;j<len-1;j++)
        {
            if(sec_hit[ary[j]-'A']==1)
            {
                continue;
            }
            else
            {
                sec_hit[ary[j]-'A'] = 1;
            }
            for(k=0;k<26;k++)
            {
                third_hit[k] = 0;
            }
            for(k=j+1;k<len;k++)
            {
                if(third_hit[ary[k]-'A']==1)
                {
                    continue;
                }
                else
                {
                    third_hit[ary[k]-'A'] = 1;
                }
                
                tmpA = ary[i];
                tmpB = ary[j];
                tmpC = ary[k];

                resize_ary[0] = tmpA;
                resize_ary[1] = tmpB;
                resize_ary[2] = tmpC;
                //printf("%s\n",resize_ary);
                times++;
                count = count + hit_fun(resize_ary,cmp);
            }
        }
    }
    printf("times %d\n",times);
    
    return count;
}



int hit_fun(char test[3],char target[26][26][26])
{
    int i,j,k;
    FILE *fout;
    
    if(target[test[0]-'A'][test[1]-'A'][test[2]-'A']==0)
    {
        target[test[0]-'A'][test[1]-'A'][test[2]-'A'] = 1;
        //printf("MISS\n");
        //printf("%c %c %c\n",test[0],test[1],test[2]);
        
        //fprintf(fout,"close\n");
        //fprintf(fout,"sort %s\n",test);    
        // fout = fopen("output","a");
        // fprintf(fout,"%c %c %c %c\n",test[0],test[1],test[2],test[3]);
        // fclose(fout);
        return 1;
    }
    else
    {

        //printf("HIT\n");
        //printf("%c %c %c\n",test[0],test[1],test[2]);
        return 0;
    }
    
}

int fprint_sort(char ary[3])
{
    FILE *fout;
    fout = fopen("every_sort","w+t");
    fprintf(fout,"%s\n",ary);
    
}