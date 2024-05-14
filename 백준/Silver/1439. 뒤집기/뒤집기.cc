#include<stdio.h>
#include <string.h> 

int main()
{
	char s[1000000];
    int cnt=0;
    scanf("%s",s);

    if(strlen(s)==1){
        printf("0");
        return 0;
    }
    for(int i = 1; i < strlen(s); i++){
        if(s[i]!=s[i-1])cnt++;
    }
	
    printf("%d", (cnt+1)/2);
}

