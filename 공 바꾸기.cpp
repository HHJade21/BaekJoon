#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, a, b, c;
    cin >> n >> m;
    int k[101];
    for(int i = 1; i <= 100; i++){
        k[i] = i;
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        c = k[a];
        k[a] = k[b];
        k[b] = c;
    }

    for(int i = 1; i <= n; i++){
        cout << k[i] << " ";
    }

}