#include<stdio.h> 
#include<string.h> 

int main(){
    int n, ans=0;
    char cmd[10000];
    scanf("%d",&n);
    
    while(n--){
        scanf("%s",cmd);
        int cnt = 0;
        for(int i = 0; i < strlen(cmd); i++){
            if(cmd[i]=='f' && cmd[i+1]=='o'&& cmd[i+2]=='r')cnt++;

            if(cmd[i]=='w' && cmd[i+1]=='h' && cmd[i+2]=='i' && cmd[i+3]=='l' && cmd[i+4]=='e')cnt++;
        }

        if(cnt>ans)ans=cnt;
    }

    printf("%d",ans);
}