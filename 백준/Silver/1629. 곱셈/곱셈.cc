#include<stdio.h> 
long long a, b, c, ans;


long long jegob(long long jisu){
    if(jisu==1) return a%c;

    long long result = jegob(jisu/2)%c;

    if(jisu%2==0){
        return result*result%c;
    }
    else{
        return ((result*result%c)*a)%c;
    }
}

int main(){

    scanf("%lld %lld %lld", &a, &b, &c);

    printf("%lld", jegob(b));
}