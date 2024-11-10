#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, ind[1001]={0,},cnt=0,a,b,ans[1001]={0,};
    vector<int>g[1001];
    queue<int>q;

    cin>>n>>m;
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        ind[b]++;
        g[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(ind[i]==0){
            q.push(i);
        }
    }

    while(q.size()){
        int size = q.size();
        cnt++;
        for(int i = 0; i < size; i++){
            int now = q.front();
            q.pop();
            ans[now]=cnt;
            for(auto j : g[now]){
                if(--ind[j]==0)q.push(j);
            }
        }
    }
    for(int i = 1; i <= n; i++)cout << ans[i] << " ";
}