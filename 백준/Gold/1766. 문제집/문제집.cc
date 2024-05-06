#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        return a>b;//오름차순 정렬
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m,a,b;
    cin >> n >> m;
    vector<int>ind(n+1,0);
    vector<int>g[n+1];
    priority_queue<int, vector<int>, cmp>q;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        ind[b]++;
        g[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(!ind[i])q.push(i);
    }

    while(!q.empty()){
        int now = q.top();
        cout << now << " ";
        q.pop();

        for(auto i : g[now]){
            if(--ind[i]==0){
                q.push(i);
            }
        }
    }

}