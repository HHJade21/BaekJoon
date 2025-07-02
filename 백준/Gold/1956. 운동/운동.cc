#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<vector<int>> g(401, vector<int>(401, 10000000));
int v, e,a,b,c,ans=INT_MAX;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>> v>> e;

    for(int i = 0; i < e; i++){
        cin>>a>>b>>c;
        g[a][b]=c;
    }
    //일단 플로이드워셜 돌린다
    for(int k = 1; k <= v; k++){//k점을 경유하는 모든 최단경로
        for(int i = 1; i <= v; i++){
            for(int j = 1; j <=v; j++){

                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }


    //2중for문으로 두 정점간 왕복경로의 합의 최소값을 찾는다.

    for(int i = 1; i <v; i++){
        for(int j = i+1; j <=v; j++){
            ans= min(ans, g[i][j]+g[j][i]);
        }
    }
    if(ans>=10000000)cout<<-1;
    else cout << ans;
}