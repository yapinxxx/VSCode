#include <stdio.h>
#include <stdlib.h>
#define max_size 100000
int my_strlen(char ary[max_size]);
//ctrl + alt + n
int main()
{
    int c,len;
    char ary[max_size];
	FILE *fin, *fout;
    fin = fopen("inputA","rt");
    fout = fopen("long_test","w+t");
    if(fin==NULL||fout==NULL)
    {
        printf("Wrong Open\n");
        getchar();
    }
    fscanf(fin,"%s",ary);
    len = my_strlen(ary);
    fprintf(fout,"len %d\n",len);
    fprintf(fout,"%s\n",ary);
    
	
	while((c=getchar())!='\n'&&c!=EOF);
    getchar();
    return 0;

}

int my_strlen(char ary[max_size])
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
