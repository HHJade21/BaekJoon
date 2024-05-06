#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m,a,b,t;
    cin >> n >> m;
    int indegree[n+1]={0,};
    vector<int>g[n+1];
    queue<int>q;
    vector<int> ans;
    for(int i = 0; i < m; i++){
        cin >> t;
        cin>>a;
        for(int j = 1; j < t; j++){
            cin >> b;
            indegree[b]++;
            g[a].push_back(b);
            a=b;
        }
    }
    for(int i = 1; i <= n; i++) if(indegree[i]==0)q.push(i);
    while(!q.empty()){
        int now = q.front();
        ans.push_back(now);
        q.pop();
        for(auto i : g[now]){
            if(--indegree[i]==0) q.push(i);
        }
    }
    if(ans.size()<n) cout << 0;
    else{
        for(auto i : ans)cout << i << "\n";
    }
}