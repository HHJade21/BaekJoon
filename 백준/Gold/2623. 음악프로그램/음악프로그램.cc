#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m,a,b,t;

    cin >> n >> m;
    int indegree[n+1]={0,};
    vector<int>g[n+1];
    queue<int>q;
    for(int i = 0; i < m; i++){
        cin >> t;
        for(int j = 0; j < t; j++){
            cin >> b;
            if(j==0){
                a=b;
                continue;
            }
            indegree[b]++;
            g[a].push_back(b);
            a=b;
        }
    }

    for(int i = 1; i <= n; i++){
        if(indegree[i]==0)q.push(i);
    }
    if(q.size()==0){
        cout << 0;
        return 0;
    }
    vector<int> ans;
    while(!q.empty()){
        int now = q.front();
        ans.push_back(now);
        q.pop();

        for(auto i : g[now]){
            if(--indegree[i]==0){
                q.push(i);
            }
            else if(indegree[i]<0){
                cout << 0;
                return 0;
            }
        }
    }
    if(ans.size()<n){
        cout << 0;
        return 0;
    }
    for(auto i : ans)cout << i << "\n";
}