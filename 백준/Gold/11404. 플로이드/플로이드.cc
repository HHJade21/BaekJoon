#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m,a,b,c;
    cin >> n >>m;

    vector<vector<int>>g(n+1,vector<int>(n+1,1000000000));
    for(int i = 1; i <= n; i++)g[i][i]=0;

    while(m--){
        cin >> a >> b >> c;
        g[a][b]=min(g[a][b],c);
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j <= n; j++){
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(g[i][j]==1000000000)cout << 0 << " ";
            else cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}