#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, color[500001]={0,}, cnt = 1;
    cin >> n;
    m = sqrt(n);
    color[1] = 1;
    for(int i = 2; i <= m; i++){
        if(!color[i]){
            cnt++;
            for(int j = i; j <= n; j+=i){
                color[j] = cnt;
            }
        }
    }
    for(int i = m+1; i<=n; i++){
        if(!color[i]){
            color[i] = ++cnt;
        }
    }

    cout << cnt << "\n";
    for(int i = 1; i <= n; i++){
        cout << color[i] << " ";
    }
}