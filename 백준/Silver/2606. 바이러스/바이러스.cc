#include<iostream>
using namespace std;
int n, m, graph[101][101]={0,},a,b,cnt=0,visited[101]={0,};

void dfs(int now){
    for(int i = 1; i<=n; i++){
        if(graph[now][i] == 1 && visited[i]==0){
            visited[i]=1;
            cnt++;
            dfs(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    visited[1]=1;
    dfs(1);
    cout << cnt;
}