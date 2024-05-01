#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, s, tmp=0, l=0, r=0, min=INT_MAX;

    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    while(l<=r){
        if(tmp>=s){
            min = min<r-l?min:r-l;
            tmp-=a[l++];
        }
        else if(r==n)break;
        else tmp+=a[r++];
    }

    if(min==INT_MAX) cout<< 0;
    else cout << min;
}