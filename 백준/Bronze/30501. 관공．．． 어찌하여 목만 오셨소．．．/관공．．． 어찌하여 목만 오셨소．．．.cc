#include<stdio.h> 
#include<string.h> 

int main(){
    int n, ans=0;
    char cmd[10000];
    scanf("%d",&n);
    
    while(n--){
        scanf("%s",cmd);
        for(int i = 0; i < strlen(cmd); i++){
            if(cmd[i]=='S'){
                printf("%s", cmd);
                return 0;
            }
        }
    }

}