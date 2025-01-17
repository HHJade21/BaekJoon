#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,m,a,b,t;
vector<vector<int>> dis(1001,vector<int>(1001,1000000));

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    while(m--){
        cin>>a>>b>>t;
        dis[a][b]=t;
    }
    for(int i = 1; i <= n; i++)dis[i][i]=0;

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i==j || i == k || j == k)continue;
                dis[i][j]=min(dis[i][j], dis[i][k]+ dis[k][j]);
            }
        }
    }

    int k;
    cin>>k;
    vector<int>cities(k);
    for(int i = 0; i < k; i++)cin>>cities[i];
    vector<int>result;

    int ans=INT_MAX, tmp=0;
    //1번째 도시부터 n번째 도시까지 전부 x로 골라보고, for문을 통해 왕복거리의 최대값을 구함.
    for(int i = 1; i <= n; i++){
        tmp=0;
        for(auto j : cities){
            if(tmp<dis[i][j]+dis[j][i])tmp=dis[i][j]+dis[j][i];
        }
        if(ans>tmp){
            result = vector<int>();
            result.push_back(i);
            ans=tmp;
        }
        else if(ans==tmp){
            result.push_back(i);
        }
    }

    for (auto i : result)cout<< i << " ";
}