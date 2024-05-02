#include<iostream>
#include<vector>
using namespace std;
vector<bool> isprime(4000001, 0);
vector<int> prime;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    for(int i = 2; i <= 2000; i++){
        if(isprime[i])continue;
        
        prime.push_back(i);
        for(int j = i*2;j<=4000000;j+=i){
            isprime[j]=true;
        }
    }

    for(int i = prime.back()+1; i<4000000;i++){
        if(!isprime[i])prime.push_back(i);
    }

    int l=0, r=0, n, cnt=0, sum = 0;
    cin>>n;
    while(l<=r){

        if(sum <= n && r < prime.size())sum+=prime[r++];
        else sum-=prime[l++];
        
        if(sum==n)cnt++;

    }
    cout << cnt;
}