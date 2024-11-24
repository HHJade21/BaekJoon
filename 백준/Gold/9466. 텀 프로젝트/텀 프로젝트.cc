#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

//order배열을 만들어서, 현재 탐색에서 몇 번째였는지 cnt값을 저장한다. 
//dfs를 돌면서, vis가 현재 이전 노드와 같은 정점에 방문하는 순간 order의 차만큼 ans에 더해진다. dfs는 종료.
//첫 정점부터 for문으로 쭉 확인. vis가 0인 정점이 있으면 거기서 시작해서 dfs. dfs 호출전에 일단 order은 증가시키기. 

vector<int>g;
vector<int> vis;
vector<int> order;
int ans,tmp,cnt;


void dfs(int now){
    vis[now]=tmp;
    order[now] = ++cnt;

    int next = g[now];
    if(vis[next]==vis[now]){//사이클 발견한 경우
        ans+=order[now]-order[next]+1;
        return;
    }
    else if(vis[next]==0){
        dfs(next);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t,n,a,cnt;
    cin >> t;

    while(t--){
        cin >> n;
        g=vector<int>(n+1,0);
        vis=vector<int>(n+1,0);
        order=vector<int>(n+1,0);
        tmp=0;
        cnt=0;
        ans=0;

        for(int i = 1; i <=n; i++)cin>>g[i];
        
        for(int i = 1; i <= n; i++){
            if(vis[i]==0){
                cnt=0;
                tmp++;
                dfs(i);
            }
        }
        cout<< n-ans<<"\n";
    }
}