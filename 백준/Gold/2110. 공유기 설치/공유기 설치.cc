#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, c,ans=0;
    cin >> n >> c;
    vector<int> wifi(n);
    for(int i = 0 ; i < n; i++)cin>>wifi[i];
    sort(wifi.begin(),wifi.end());

    int l = 1, r = wifi[n-1]-wifi[0];

    while(l<=r){
        int mid = (l+r)/2, cnt = 1, pre = 0;
        for(int i = 1; i < n; i++){
            if(wifi[i]-wifi[pre]>=mid){
                cnt++;
                pre = i;
            }
        }

        if(cnt>=c){
            ans=mid;
            l = mid+1;
        }
        else r = mid-1;
    }

    cout << ans;
}