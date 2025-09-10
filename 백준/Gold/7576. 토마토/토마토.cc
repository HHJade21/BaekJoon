#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int map[1001][1001],n,m,dy[4]={1,-1,0,0},dx[4]={0,0,1,-1},cnt=0,v[1001][1001],day=-1;
queue<pair<int,int>>q;

void bfs(){
    while(!q.empty()){
        int size= q.size();
        day++;
        for(int i = 0; i < size; i++){
            int y = q.front().first, x = q.front().second;
            q.pop();
            for(int j = 0; j<4; j++){
                int ny = y+dy[j], nx = x+dx[j];//전후좌우 탐색 좌표
                if(ny<=0 || nx<=0|| ny>n || nx>m)continue;
                if(map[ny][nx]!=0)continue;
                if(v[ny][nx])continue;
                q.push({ny,nx});
                v[ny][nx]=1;
                cnt--;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>m>>n;
    for(int i = 1 ;i <= n;i++){
        for(int j = 1; j<=m; j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                q.push({i,j});
                v[i][j]=1;
            }
            else if(map[i][j]==0)cnt++;
        }
    }
    if(cnt==0){
        cout<<0;
        return 0;
    }
    bfs();
    if(cnt==0)cout<<day;
    else cout<<-1;
}