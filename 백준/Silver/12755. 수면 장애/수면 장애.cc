#include<stdio.h> 
#include<string.h> 

/*
1자리수 : 1~9 9개
2자리수 : 10~99 90개

3자리수 : 100~999 900개


*/

int main(){
    int n;
    scanf("%d", &n);

    int gaesu = 9, jari = 1, now = 1, ans = 0;
    int cnt = 0;
    while(n>jari){
        now++;
        n-=jari;
        cnt++;
        if(cnt==gaesu){
            gaesu*=10;
            cnt=0;
            jari++;
        }

    }
    n = jari-n + 1;

    while(n--){
        ans = now %10;
        now/=10;
    }

    printf("%d",ans);
}