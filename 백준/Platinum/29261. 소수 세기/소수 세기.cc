#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<cmath>
using namespace std;

bool isprime[3000001]={0,};
vector<int> dp(3000000,1);
vector<int> prime;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    isprime[0]=1;
    isprime[1]=1;
    int ans = 0;
    int n;
    cin >> n;
    for(int i = 2; i < sqrt(3000000);i++){
        if(isprime[i])continue;

        prime.push_back(i);
        for(int j = i*2; j<3000000; j+=i)isprime[j]=1;
    }

    for(int i = 2; i < 3000000; i++){
        if(isprime[i])continue;

        for(auto j : prime){
            if(i+j+1>=3000000)break;
            if(isprime[i+j+1]==1)continue;

            dp[i+j+1] = max(dp[i+j+1], dp[i]+dp[j]+1);
        }
    }
    cout << dp[n];
}
