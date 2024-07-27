#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

struct cmp{
    bool operator()(pair<int,int>a, pair<int,int>b){
        return a.second>b.second;
    }
};
priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;



int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m,s,e,w, start, dest;
    cin >> n >> m;


    vector<pair<int,int>>g[n+1];
    vector<long long>dist(n+1,LONG_LONG_MAX);
    for(int i = 0; i < m; i++){
        cin >> s >> e >> w;
        g[s].push_back({e,w});

    }

    cin >> start >> dest;

    dist[start]=0;
    q.push({start,0});

    vector<bool>visited(n+1,0);
    vector<int>before(n+1,0);

    while(!q.empty()){
        int now = q.top().first;
        q.pop();
        if(visited[now])continue;
        visited[now]=true;

        for(auto i : g[now]){
            if(dist[i.first] > dist[now]+i.second){
                before[i.first]=now;
                dist[i.first]=dist[now]+i.second;
                q.push({i.first, dist[i.first]});
            }
        }
    }

    cout << dist[dest] << "\n";

    // int cnt=0;
    // for(int i = 1; i <= n; i++){
    //     if(dist[i]==dist[dest])cnt++;
    // }
    // cout << cnt << "\n";

    int idx=dest;
    vector<int>ans;
    ans.push_back(dest);
    while(idx!=start){
        idx = before[idx];
        ans.push_back(idx);
    }
    
    cout << ans.size() << "\n";

    for(int i = ans.size()-1; i>=0; i--)cout << ans[i] << " ";
}