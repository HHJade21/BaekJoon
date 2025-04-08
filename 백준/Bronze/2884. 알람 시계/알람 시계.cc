#include<stdio.h> 
int main(){
    int h,m;
    scanf("%d %d",&h,&m);
    printf("%d %d", h*60+m-45<0?23:m<45?h-1:h,m<45?m+15:m-45);
}