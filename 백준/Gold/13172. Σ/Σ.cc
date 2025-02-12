#include<iostream>
#include<vector>
#include<algorithm>//__gcd(최대공약수)구하는 함수 가져올 라이브러리
using namespace std;
long long MOD = 1000000007,n,s,res=0;
int m;

long long j(long long a,long long b){//밑,지수 제곱함수
    if(b==1) return a;
    
    long long ans = j(a,b/2)%MOD;
    if(b%2) return ((a*ans)%MOD)*ans%MOD;
    else return (ans*ans)%MOD;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>m;

    while(m--){
        cin>>n>>s;
        //n과 s의 기약분수 찾기
        long long g = __gcd(n,s);
        n /= g;
        s /= g;
        res = (res + (s*j(n, MOD-2)%MOD)%MOD)%MOD;
    }
    cout<<res;
}