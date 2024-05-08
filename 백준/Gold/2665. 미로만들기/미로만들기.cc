#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h> 
using namespace std;
int n, dy[4]={0,0,-1,1},dx[4]={-1,1,0,0};
vector<vector<int>>map(50, vector<int>(50));
vector<vector<int>>dist(50, vector<int>(50, INT_MAX));
vector<vector<bool>>visit(50, vector<bool>(50,false));
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
priority_queue<node, vector<node>,cmp>q;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        for(int j = 0; j < n; j++)map[i][j]=int(s[j]-'0'+1)%2;
    }
    dist[0][0]=0;
    q.push({0,0,0});

    while(q.size()){
        int y=q.top().y, x=q.top().x;
        q.pop();
        if(visit[y][x])continue;
        visit[y][x]=true;

        for(int i = 0; i < 4; i++){
            int ny = y+dy[i], nx = x+dx[i];
            if(ny<0||ny>=n||nx<0||nx>=n||visit[ny][nx])continue;
            if(dist[ny][nx]>=dist[y][x]+map[ny][nx]){
                dist[ny][nx]=dist[y][x]+map[ny][nx];
                q.push({ny,nx,dist[ny][nx]});
            }
        }
    }

    cout << dist[n-1][n-1];
}