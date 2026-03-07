#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,k;
long long ans=0,cow[100001],dp[100001]={},psum[100001]={};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    deque<pair<long long,int>>dq;
    dq.push_back({0,0});
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>cow[i];
        psum[i]=cow[i]+psum[i-1];//누적합 계산

        while(dq.size()&&dq.front().second< i - k )dq.pop_front();
        dp[i] = psum[i]+dq.front().first;

        while(dq.size()&&dq.back().first <= dp[i-1]-psum[i])dq.pop_back();
        dq.push_back({dp[i-1]-psum[i],i});
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout<<dp[n];
}