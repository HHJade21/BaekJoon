#include<stdio.h> 
int main(){
    int h,m,k;
    scanf("%d %d %d",&h,&m,&k);
    printf("%d %d", (h*60+m+k)%(24*60)/60, (h*60+m+k)%60);
}