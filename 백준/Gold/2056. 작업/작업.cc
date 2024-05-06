#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int ans=0,n, time[10001],start[10001]={0,},a,b,k,ind[10001]={0,};
    cin >> n;
    vector<int>g[n+1];
    queue<int>q;

    for(int i = 1; i<=n; i++){
        cin >> time[i] >> k;
        ind[i]+=k;
        for(int j = 0; j < k; j++){
            cin >> a;
            g[a].push_back(i);
        }
    }

    for(int i = 1; i <= n; i++){
        if(ind[i]==0)q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        ans=ans>=start[now]+time[now]?ans:start[now]+time[now];

        for(auto i : g[now]){
            if(--ind[i]==0)q.push(i);
            start[i]=max(start[now]+time[now], start[i]);
        }
    }

    cout << ans;
}