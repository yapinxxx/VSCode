#include <stdio.h>
#include <stdlib.h>
int factorial(int num);
//ctrl + alt + n
int main()
{
    int c,num,ans;
	
	
	
	scanf("%d",&num);
    ans = factorial(num);
    printf("%d\n",ans);
	
	
	
	
	
	
	while((c=getchar())!='\n'&&c!=EOF);
    getchar();
    return 0;

}

int factorial(int num)
{
    if(num==0)
    {
        return 1;
    }
    else
    {
        return factorial(num-1)*num;
    }
    
}