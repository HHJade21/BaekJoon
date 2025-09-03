#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

vector<vector<bool>>vis;
vector<vector<char>>map;
queue<pair<int,int>>q;
vector<bool>key(26,false);
int t,h,w,ans, dy[4]={1,-1,0,0}, dx[4]={0,0,-1,1};

void bfs(){
    while(q.size()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny<0||nx<0||ny>h+1||nx>w+1)continue;
            char next = map[ny][nx];
            if(next == '*')continue;
            if(vis[ny][nx]==1)continue;
            if((next >= 'A' && next <= 'Z') && !key[next-'A']){
                continue;
            }
            
            if(next >='a' && next <= 'z') key[next-'a']=true;
            else if(next == '$'){
                map[ny][nx]='.';
                ans++;
            }
            q.push({ny,nx});
            vis[ny][nx]=true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>t;
    while(t--){
        cin>>h>>w;
        vis = vector<vector<bool>>(h+2, vector<bool>(w+2,0));
        map = vector<vector<char>>(h+2, vector<char>(w+2,'.'));
        q = queue<pair<int,int>>();
        key = vector<bool>(26,false);
        ans=0;
        string s;
        for(int i = 1 ; i <= h; i++){
            cin>>s;
            for(int j = 1; j <= w; j++){
                map[i][j] = s[j-1];
            }
        }
        cin>>s;
        if(s!="0"){
            for(auto c : s) key[c-'a']=true;
        }

        for(int i = 0; i < 27; i++){
            q = {};
            vis = vector<vector<bool>>(h+2, vector<bool>(w+2,0));
            q.push({0,0});
            bfs();
        }
        cout<<ans<<"\n";
    }
}