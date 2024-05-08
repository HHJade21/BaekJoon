#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
    int city;
    int time;
};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, a, b, t, strt, dest;
    cin >> n >> m;
    vector<int>ind(n+1,0);
    vector<int>start(n+1,0);//임계경로 배열
    queue<int>q;
    vector<node>g[n+1];
    vector<node>rg[n+1];


    for(int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        ind[b]++;
        g[a].push_back({b,t});
        rg[b].push_back({a,t});
    }
    cin >> strt >> dest;
    q.push(strt);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto i : g[now]){
            if(--ind[i.city]==0)q.push(i.city);
            int arrive = start[now]+i.time;
            if(arrive>start[i.city]){
                start[i.city]=arrive;
            }
        }
    }

    bool visited[n+1]={0,};

    q.push(dest);
    visited[dest]=true;
    int cnt=0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto i : rg[now]){
            int arrive = start[i.city]+i.time;
            if(arrive==start[now]){
                if(!visited[i.city]){
                    q.push(i.city);
                    visited[i.city]=true;
                }
                cnt++;
            }
        }
    }

    cout << start[dest] << "\n" << cnt;
}