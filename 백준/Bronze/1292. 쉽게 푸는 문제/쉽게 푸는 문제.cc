#include<stdio.h> 
#include<string.h> 

int num[1001];

int main(){
    int now=1, cnt=0, a, b;
    scanf("%d %d", &a, &b);
    for(int i = 1; i <= 1000; i++){
        num[i]=now;
        cnt++;
        if(cnt==now){
            cnt=0;
            now++;
        }
    }

    int sum=0;
    for(int i = a; i <= b; i++){
        sum += num[i];
    }
    printf("%d",sum);
}