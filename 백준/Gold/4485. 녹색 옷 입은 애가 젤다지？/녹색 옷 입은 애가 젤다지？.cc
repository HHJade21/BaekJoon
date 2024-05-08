#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int dy[4]={-1,1,0,0}, dx[4]={0,0,-1,1};
struct node{
    int y;
    int x;
    int w;
};

struct cmp{
    bool operator()(node a,node b){
        return a.w>b.w;
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t=1,n;
    cin >> n;
    while(n){
        vector<vector<int>>map(n,vector<int>(n,0));
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        priority_queue<node, vector<node>,cmp>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
            }
        }
        dist[0][0]=map[0][0];
        q.push({0,0,map[0][0]});

        while(q.size()){
            int y = q.top().y,x = q.top().x;
            q.pop();
            if(visited[y][x])continue;
            visited[y][x]=true;

            for(int i = 0; i <4; i++){
                int ny=y+dy[i], nx=x+dx[i];
                if(ny<0||ny>=n||nx<0||nx>=n||visited[ny][nx])continue;
                if(dist[y][x]+map[ny][nx]>=dist[ny][nx])continue;
                dist[ny][nx]=dist[y][x]+map[ny][nx];
                q.push({ny,nx,dist[ny][nx]});
            }
        }
        cout << "Problem " << t++ << ": "<< dist[n-1][n-1] << "\n";
        cin >> n;
    }
}