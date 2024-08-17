#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, danji=0,cnt, dy[4]={-1,1,0,0}, dx[4]={0,0,-1,1};
vector<vector<int>> map(25, vector<int>(25,0));
vector<vector<bool>> vis(25, vector<bool>(25,0));
vector<int> danjiCnt;

void dfs(int y, int x){
    vis[y][x]=true;
    map[y][x]=danji;
    cnt++;
    for(int i = 0; i < 4; i++){
        int ny = y+dy[i];
        int nx = x + dx[i];

        if(ny<0||nx<0||ny>=n||nx>=n)continue;
        if(vis[ny][nx]||map[ny][nx]==0)continue;

        dfs(ny,nx);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;

    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        for(int j = 0;j<n;j++){
            map[i][j]=s[j]-'0';
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j<n; j++){
            if(map[i][j] && !vis[i][j])
            {
                cnt=0;
                danji++;
                dfs(i,j);
                danjiCnt.push_back(cnt);
            }
        }
    }

    cout << danji << "\n";
    sort(danjiCnt.begin(), danjiCnt.end());
    for(auto i : danjiCnt)cout<<i << "\n";
}