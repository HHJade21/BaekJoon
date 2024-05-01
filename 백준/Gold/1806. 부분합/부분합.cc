#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, s, tmp=0, l=0, r=0, min=INT_MAX;

    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    while(r<n){
        if(tmp<s) tmp+=a[r++];
        else if(l==r)break;
        else if(l<r) tmp-=a[l++];
        

        if(tmp>=s) min = min<r-l?min:r-l;
    }
    while(tmp>=s && l<r){
        min = min<r-l?min:r-l;
        tmp -= a[l++];
    }

    if(min==INT_MAX) cout<< 0;
    else cout << min;
}