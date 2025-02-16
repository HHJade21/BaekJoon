#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<int>g[100001];
bool vis[100001];
int dp[100001][20];
int n,a,b;

void dfs(int now){
    vis[now]=true;
    for(int i = 1; i<=19; i++)dp[now][i]=i;
    for(auto i : g[now]){
        if(vis[i])continue;
        dfs(i);
        //이제 해야 하는 것 : now의 색깔이 1~19일때, 각각 i번 노드의 dp값 중 최소를 dp[now][1~19]에 더하기.
        int min1=INT_MAX, min2=INT_MAX,minIdx=0;
        for(int j = 1; j<=19; j++){//여기서 min1, min2 둘 중 하나에만 들어갈 수 있다는 게 문제다!!
            if(dp[i][j]<min1){
                minIdx=j;
                min1=dp[i][j];
            }
        }//dp[i][minIdx]가 최솟값이다.
        for(int j = 1; j <=19; j++){
            if(j==minIdx)continue;
            min2 = min(min2, dp[i][j]);
        }
        for(int j = 1; j<=19; j++){
            if(j==minIdx)dp[now][j]+=min2;
            else dp[now][j]+=min1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i = 1; i <n; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    int ans = INT_MAX;
    for(int i = 1; i <=19; i++){
        ans = min(dp[1][i], ans);
    }
    cout<<ans;
}