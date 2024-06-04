#include<stdio.h> 
#include<string.h> 

int main(){
    char s[100];
    scanf("%s",s);

    if(strlen(s)<3){
        printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
        return 0;
    }

    for(int i = 2; i < strlen(s); i++){
        if(s[i]-s[i-1] != s[i-1]-s[i-2]){
            printf("흥칫뿡!! <(￣ ﹌ ￣)>");
            return 0;
        }
    }

    printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
        return 0;
}