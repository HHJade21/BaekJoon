#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n, last = 0, now = 0, dist = 0;
    long long ans = 0;
    cin >> n;

    vector<long long>road(n,0);
    vector<long long>oil(n,0);

    for(int i = 0; i< n-1; i++){
        cin>>road[i];
    }

    for(int i = 0; i < n; i++){
        cin >> oil[i];
    }

    while(now<n){
        if(oil[last]<=oil[now]){
            dist+=road[now++];
        }
        else{
            ans+=dist*oil[last];
            last=now;
            dist=0;
        }
    }
    ans+=dist*oil[last];
    cout << ans;
}