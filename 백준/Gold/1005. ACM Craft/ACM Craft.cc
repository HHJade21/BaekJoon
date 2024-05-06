#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t, n, k, x, y, w;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> graph[n+1];
        vector<int> indegree(n+1, 0);
        vector<int> time(n+1);
        vector<int> start(n+1,0);
        queue<int> q;
        for(int i = 1; i <= n; i++) cin >> time[i];
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            indegree[y]++;
            graph[x].push_back(y);
        }
        cin >> w;

        for(int i = 1; i <= n; i++){
            if(!indegree[i]){
                q.push(i);
            }
        }

        while(!q.empty()){
            int now = q.front();
            if(now == w){
                cout << start[w]+time[w] << "\n";
                break;
            }
            q.pop();
            for(auto i : graph[now]){
                start[i] = max(start[now]+time[now], start[i]);
                if(--indegree[i]==0){
                    q.push(i);
                }
            }
        }
    }


}