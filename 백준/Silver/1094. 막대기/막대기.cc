#include<stdio.h> 

int main(){
    int x,ans=0;
    scanf("%d",&x);

    while(x){
        int a = 64;
        while(a){
            if(x>=a){
                x-=a;
                ans++;
            }
            a/=2;
        }
    }
    printf("%d",ans);
}