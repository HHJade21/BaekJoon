#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,m,cnt,ans,temp;
int map[500][500], vis[500][500],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};


void dfs(int y, int x){
    vis[y][x]=1;
    temp++;
    for(int i = 0 ; i < 4; i++){
        int ny = y+dy[i], nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m)continue;
        if(vis[ny][nx])continue;
        if(map[ny][nx]==0)continue;
        dfs(ny,nx);
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin>>map[i][j];
        }
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(map[i][j]==1 && vis[i][j]==0){
                temp=0;
                cnt++;
                dfs(i,j);
                ans = max(temp,ans);
            }
        }
    }
    cout<<cnt << " " << ans;
}