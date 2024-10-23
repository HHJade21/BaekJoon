#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int ans=0;
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0 ; i < n; i++){
        cin>>a[i];
    }
    vector<int>LIS(n,1);
    vector<int>LDS(n,1);

    for(int i = 0; i< n; i++){
        for(int j = 0; j < i ;j++){
            if(a[j]<a[i])LIS[i]=max(LIS[i],LIS[j]+1);
        }
    }
    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>i; j--){
            if(a[j]<a[i])LDS[i]=max(LDS[i],LDS[j]+1);
        }
    }

    for(int i = 0; i < n; i++){
        ans = max(ans, LIS[i]+LDS[i]-1);
    }
    cout<<ans;

}