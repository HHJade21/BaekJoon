#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    bool prime[1001]={0,};
    int n, k, cnt=0,ans;
    cin >> n >> k;
    for(int i = 2; i<=n;i++){
        if(prime[i]==1)continue;
        for(int j = i; j<=n; j+=i){
            if(prime[j]==1)continue;
            prime[j]=1;
            cnt++;
            if(cnt==k){
                cout << j;
                return 0;
            }
        }
    }
}