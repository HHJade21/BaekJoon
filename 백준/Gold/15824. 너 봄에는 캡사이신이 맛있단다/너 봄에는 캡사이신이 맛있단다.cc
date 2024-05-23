#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

vector<long long>two(300001);

void square(){
    long long sum = 0;
    long long tmp = 1;
    for(int i = 0; i <= 300000; i++){
        sum = (sum+tmp)%1000000007;
        two[i]=sum;
        tmp = (tmp*2)%1000000007;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    long long ans=0;
    cin >> n;
    vector<long long>a(n,0);
    for(int i = 0; i < n; i++)cin>>a[i];

    sort(a.begin(),a.end());

    square();

    for(int i = 0; i <= n-2; i++){
        ans = (ans + a[i+1]*two[i]- a[n-2-i]*two[i])%1000000007;
    }

    cout << ans%1000000007;
}