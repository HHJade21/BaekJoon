#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, r, s, e, w, ans=0;
    cin >> n >> m >> r;
    vector<vector<int>> dist(n+1,vector<int>(n+1,987654321));
    vector<int>item(n+1);
    
    //구역별 아이템 개수 입력
    for(int i = 1; i <= n; i++)cin >> item[i];

    //dist 초기화
    for(int i = 0; i < r; i++){
        cin >> s >> e >> w;
        dist[s][e]=w;
        dist[e][s]=w;
    }
    for(int i = 1; i <=n; i++)dist[i][i]=0;

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <=n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }   

    for(int i = 1; i<=n; i++){
        int tmp = 0;
        for(int j = 1; j <= n; j++){

            if(dist[i][j]<=m){
                tmp+=item[j];
            }
        }
        if(tmp>ans)ans=tmp;
    }

    cout << ans;
}