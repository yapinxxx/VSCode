#include <stdio.h>
#include <stdlib.h>
//ctrl + alt + n
int main()
{
    int in1[45][2],in2[45][2],i,count,ans;
    FILE *fin1,*fin2,*fout;
  
    fin1 = fopen("outputB.txt","rt");//rt read text
    fin2 = fopen("ansB.txt","rt");
    fout = fopen("TorF.txt","w+t");//w+t write text
    if(fin1==NULL&&fin2==NULL) 
    {

        printf("Fail To Open File xxx!!");
        getchar();
        return 0;

    }
    
    i=0;
    while(in1[i-1][0]!=27 || in1[i-1][1]!=3)
    {
        
        fscanf(fin1," %d %d",&in1[i][0],&in1[i][1]);
        printf("%d %d\n",in1[i][0],in1[i][1]);
        i++;
        
    }
    ans = i;

    i=0;
    while(in2[i-1][0]!=27||in2[i-1][1]!=3)
    {
        fscanf(fin2," %d %d",&in2[i][0],&in2[i][1]);
        i++;
    }
    
    count = 0;
    for(i=0;i<45;i++)
    {
        if(in1[i][0]==in2[i][0]&&in1[i][1]==in2[i][1])
        {
            count++;
        }
    }
    printf("%d %d\n",count,ans);
    if(count==ans)
    {
        fprintf(fout,"correct\n");
    }
    else
    {
        fprintf(fout,"error\n");
    }
    
    


    
    fclose(fin1);
    fclose(fin2);
    fclose(fout);
	fflush(stdin);
    getchar();
    return 0;

}