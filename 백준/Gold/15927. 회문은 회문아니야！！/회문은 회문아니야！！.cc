#include<stdio.h> 
#include<string.h> 

int ispal(char*s){

    for(int i = 0; i < strlen(s)/2; i++){
        if(s[i] != s[strlen(s)-1-i]) return 0;
    }
    return 1;
}

int issame(char* s){
    for(int i = 1; i < strlen(s); i++){
        if(s[i]!=s[i-1])return 0;
    }
    return 1;
}

int main(){
    char s[500001];
    scanf("%s",s);
    int size = strlen(s);
    if(size<=1) {
        printf("-1");
        return 0;
    }

    if(ispal(s)==0){
        printf("%d", size);
        return 0;
    }

    if(issame(s)){
        printf("-1");
        return 0;
    }
    
    printf("%d", size-1);
}