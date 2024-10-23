#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, m, dy[4]={-1,1,0,0}, dx[4]={0,0,-1,1},emp=0, time = 0, cCnt=0;

struct p{
    int y;
    int x;
};

vector<vector<int>> map;
vector<vector<bool>> vis;

queue<p> airQ;
queue<p> bfsQ;
queue<p> tmpQ;

void air(){
    while(airQ.size()){
        int size = airQ.size();
        for(int i = 0; i < size; i++){
            int y = airQ.front().y, x = airQ.front().x;
            airQ.pop();
            for(int j = 0; j < 4; j++){
                int ny = y + dy[j], nx = x + dx[j]; 
                if(ny<0||nx<0||ny>=n||nx>=m)continue;
                if(vis[ny][nx])continue;
                
                //vis[ny][nx]=true;
                if(map[ny][nx]==0) {
                    vis[ny][nx]=true;
                    airQ.push({ny,nx});
                }
                else{//치즈면 4변 확인 후 bfsQ삽입.
                    emp=0;
                    for(int k = 0; k < 4; k++){
                        int newy = ny+dy[k], newx = nx+dx[k];
                        if(newy<0||newx<0||newy>=n||newx>=m)continue;
                        if(map[newy][newx]==0)emp++;
                    }
                    if(emp>1){
                        // vis[ny][nx]=true;
                        // bfsQ.push({ny,nx});
                        tmpQ.push({ny,nx});
                    }
                    
                }
            }
        }
    }
    while(tmpQ.size()){
        int ny = tmpQ.front().y, nx = tmpQ.front().x;
        tmpQ.pop();
        if(vis[ny][nx])continue;
        emp=0;
        for(int i = 0; i < 4; i++){
            int newy= ny+dy[i], newx = nx+dx[i];
            if(newy<0||newx<0||newy>=n||newx>=m)continue;
            if(map[newy][newx]==0&&vis[newy][newx])emp++;
        }
        if(emp>1){
            vis[ny][nx]=true;
            bfsQ.push({ny,nx});
        }
    }
}

void cheese(){
    while(bfsQ.size()){
        
        int size = bfsQ.size();
        time++;
        if(airQ.size())air();
        for(int i = 0; i<size; i++){
            int y = bfsQ.front().y, x = bfsQ.front().x;
            bfsQ.pop();
            map[y][x]=0;
            for(int j = 0; j < 4; j++){
                int ny = y+dy[j],nx=x+dx[j];
                if(ny<0||nx<0||ny>=n||nx>=m)continue;
                if(vis[ny][nx])continue;
                
                //vis[ny][nx]=true;
                if(map[ny][nx]==0){
                    vis[ny][nx]=true;
                    airQ.push({ny,nx});
                }
                else{
                    emp=0;
                    for(int k = 0; k < 4; k++){
                        int newy = ny+dy[k], newx = nx+dx[k];
                        if(newy<0||newx<0||newy>=n||newx>=m)continue;
                        if(map[newy][newx]==0 && vis[newy][newx])emp++;
                    }
                    if(emp>1){
                        vis[ny][nx]=true;
                        bfsQ.push({ny,nx});
                    }
                }
            }
        }
        if(airQ.size())air();
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    map = vector<vector<int>>(n,vector<int>(m,0));
    vis = vector<vector<bool>>(n,vector<bool>(m,0));

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            cin>>map[i][j];
            if(map[i][j]==1)cCnt++;
        }
    }

    //가장자리로부터 bfs로 빈공간 전부 탐색하고, 첫번째로 녹을 치즈 큐에 넣기.
    vis[0][0]=true;
    vis[n-1][0]=true;
    vis[0][m-1]=true;
    vis[n-1][m-1]=true;
    airQ.push({0,0});
    airQ.push({0,m-1});
    airQ.push({n-1,0});
    airQ.push({n-1,m-1});
    air();
    cheese();

    cout<<time;
}