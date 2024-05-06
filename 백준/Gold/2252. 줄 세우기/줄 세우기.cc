#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, a, b;
    cin >> n >> m;
    vector<int>indegree(n+1, 0);
    queue<int> q;
    vector<int>graph[n+1];
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    for(int i = 1; i <= n; i++){
        if(!indegree[i]) q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        cout << now << " ";
        q.pop();
        for(auto i : graph[now]){
            if(--indegree[i]==0) q.push(i);
        }
    }
}