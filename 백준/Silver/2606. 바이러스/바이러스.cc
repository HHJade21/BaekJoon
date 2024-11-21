#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m,a,b;
    bool visit[101]={0,};
    int graph[101][101]={0,};

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a][b]=1;
        graph[b][a]=1;

    }

    visit[1]=true;
    queue<int>bfsQ;
    bfsQ.push(1);
    int cnt=0;

    while(!bfsQ.empty()){
        int qsize=bfsQ.size();
        for(int i = 0; i < qsize; i++){
            int now = bfsQ.front();
            for(int i = 1; i <= n; i++){
                if(graph[now][i]==1 && !visit[i]){
                    visit[i]=true;
                    bfsQ.push(i);
                    cnt++;
                }
            }
            bfsQ.pop();
        }
    }
    cout << cnt;
}