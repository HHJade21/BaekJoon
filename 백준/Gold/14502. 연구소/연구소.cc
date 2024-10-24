#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
2중for문으로 i,j+1부터 시작. map[k][l]==0이면 재귀호출. depth==3이면 bfs실행.

*/

struct p{
    int y;
    int x;
};

int map[8][8]={0,}, n, m, space=0,safe=0, ans=0, tmp,dy[4]={-1,1,0,0},dx[4]={0,0,-1,1};
vector<p> virus;
queue<p> bfsQ;
vector<vector<bool>>vis;

void bfs(){
    bfsQ={};
    for(auto i : virus) bfsQ.push({i.y, i.x});
    vis = vector<vector<bool>>(n,vector<bool>(m,0));
    tmp=space;

    while(bfsQ.size()){
        int size = bfsQ.size();
        for(int i = 0; i < size; i++){
            int y = bfsQ.front().y, x = bfsQ.front().x;
            bfsQ.pop();
            for(int j = 0; j < 4; j++){
                int ny=y+dy[j],nx=x+dx[j];
                if(ny<0||nx<0||ny>=n||nx>=m)continue;
                if(map[ny][nx]||vis[ny][nx])continue;//빈공간이 아니거나 방문했으면 건너뛰기
                
                vis[ny][nx]=true;
                bfsQ.push({ny,nx});
                tmp--;
            }
        }
    }

    ans = max(ans, tmp);
}


void dfs(int i, int j, int depth){
    if(depth==3){
        bfs();
        return;
    }

    for(int l = j+1; l < m; l++){
        if(map[i][l]==0){
            map[i][l]=1;
            dfs(i,l,depth+1);
            map[i][l]=0;
        }
    }

    for(int k = i+1; k < n; k++){
        for(int l = 0;  l < m; l++){
            if(map[k][l]==0){
                map[k][l]=1;
                dfs(k,l,depth+1);
                map[k][l]=0;
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) virus.push_back({i, j});
            else if(map[i][j] == 0) space++;
        }
    }
    space-=3;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j]==0){
                map[i][j]=1;
                dfs(i,j,1);
                map[i][j]=0;
            }
        }
    }
    cout << ans;
}
