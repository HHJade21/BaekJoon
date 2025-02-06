#include<stdio.h> 

int main(){
    char s[1000001];
    gets(s);

    int cnt=1;

    for(int i = 0; s[i]!='\0'; i++){
        if(s[i]==' '){
            cnt++;

            if(i==0){
                cnt--;
            }
            if(s[i+1]=='\0'){//i번째 자리가 문자열 s의 마지막 자리일 때
                cnt--;
            }
        }
        
    }

    printf("%d",cnt);

}