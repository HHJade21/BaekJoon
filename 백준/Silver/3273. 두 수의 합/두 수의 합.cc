#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,x,cnt=0;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    cin>>x;
    sort(a.begin(), a.end());

    int l = 0, r = a.size()-1, sum = 0;

    while(l<r){
        sum=a[l]+a[r];
        if(sum==x)cnt++;
        
        if(sum<=x){
            l++;
        }
        else{
            r--;
        }
    }
    cout<<cnt;
}