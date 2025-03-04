#include <iostream>
#include<vector>
using namespace std;
int n,u,v;
vector<int>g[1000001];
int dp[1000001][2]={};//0 : 내가 얼리어답터일때, 1: 아닐때
bool vis[1000001]={};

void dfs(int now){
    vis[now]=true;
    dp[now][0]=1;
    dp[now][1]=0;

    for(auto i : g[now]){
        if(vis[i])continue;
        dfs(i);
        //test
        //cout << "dfs " << i << "  end. dp[i][0], dp[i][1] : " << dp[i][0] <<", "<< dp[i][1]<<"\n";
        dp[now][0] += min(dp[i][1],dp[i][0]);
        dp[now][1] += dp[i][0];
        //test
        //cout<<"dp " << now << " : " << dp[now][0] << " , " << dp[now][1] << ".\n";
    }
    //test
    //cout << "finally, dp " << now << " : " << dp[now][0] << ", " << dp[now][1] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i = 1; i < n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);//루트노드인 1부터 dfs시작

    // for (int i = 1; i <= n; i++)cout<<dp[i][0]<<" "<<dp[i][1] << ", ";
    // cout<<endl;

    cout<<min(dp[1][0],dp[1][1]);
    return 0;
}   