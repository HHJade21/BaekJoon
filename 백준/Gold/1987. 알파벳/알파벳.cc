#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<vector<int>>map(20,vector<int>(20,0));
int r,c,ans=1,tmp,dy[4]={-1,1,0,0},dx[4]={0,0,-1,1};
vector<bool>visited(26,0);

void dfs(int y,int x){
    for(int i = 0; i < 4; i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(ny<0||ny>=r||nx<0||nx>=c||visited[map[ny][nx]])continue;//지도 범위를 벗어나거나 이미 방문한 알파벳이면 

        //아직 방문한 적 없는 알파벳이면
        visited[map[ny][nx]]=true;
        tmp++;
        ans=max(ans,tmp);
        dfs(ny,nx);
        visited[map[ny][nx]]=false;
        tmp--;
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> r >> c;
    string s;
    for(int i = 0; i < r; i++){
        cin>>s;
        for(int j = 0; j < c; j++){
            map[i][j]=s[j]-'A';
        }
    }

    tmp=1;
    visited[map[0][0]]=true;
    dfs(0,0);

    cout<<ans;
}