#include <stdio.h>
#include <stdlib.h>
#define data_number 45 /*can change*/
#define data_range 2	/*can change*/
//ctrl + alt + n
int main()
{
    int in1[data_number][data_range],in2[data_number][data_range],i,count,ans;
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