#include<iostream>
using namespace std;
int main(){
    long long n, m, ans=1;
    cin >> n >> m;
    if(n>=m) cout << 0;
    else {
        for(int i = 1; i <= n; i++){
            ans = (ans*i)%m;
        }
        cout << ans;
    }
}