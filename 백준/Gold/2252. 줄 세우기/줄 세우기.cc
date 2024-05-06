#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, a, b;

    cin >> n >> m;
    vector<int>poto(n+1, 0);
    queue<int> potoQ;
    vector<int>graph[n+1];
    vector<int> ans;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        poto[b]++;
    }

    for(int i = 1; i <= n; i++){
        if(!poto[i]) {
            potoQ.push(i);
            ans.push_back(i);
        }
    }

    while(!potoQ.empty()){
        int qsize = potoQ.size();
        for(int i = 0; i < qsize; i++){
            int now = potoQ.front();
            potoQ.pop();
            for(auto j : graph[now]){
                if(--poto[j]==0) {
                    potoQ.push(j);
                    ans.push_back(j);
                }
            }
        }
    }
    for(auto i : ans)cout << i << " ";
}