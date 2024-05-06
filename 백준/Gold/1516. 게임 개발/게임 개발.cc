#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    int indegree[n+1]={0,}, time[n+1], start[n+1]={0,};
    vector<int> g[n+1];
    queue<int>q;
    for(int i = 1; i<=n; i++){
        cin >> time[i];
        int a;
        cin >> a;
        while(a!=-1){
            indegree[i]++;
            g[a].push_back(i);
            cin >> a;
        }
    }
    for(int i = 1; i <= n; i++){
        if(!indegree[i])q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto i : g[now]){
            if(--indegree[i]==0){
                q.push(i);
            }
            start[i] = max(start[now]+time[now], start[i]);
        }
    }
    for(int i = 1; i <= n; i++)cout << start[i]+time[i] << "\n";
}