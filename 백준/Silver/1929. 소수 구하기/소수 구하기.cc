#include<iostream>
using namespace std;

bool prime[1000001]={1,1,};
int m,n;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>m>>n;

    for(int i = 2; i*i<=n; i++){
        if(prime[i])continue;
        for(int j = i*i; j<=n; j+=i)prime[j]=1;
    }

    for(int i = m; i<=n; i++){
        if(!prime[i])cout<<i<<"\n";
    }
}