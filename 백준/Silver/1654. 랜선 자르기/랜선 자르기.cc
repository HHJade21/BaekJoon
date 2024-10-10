#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n, k,ans=0,mid;
    cin >> k >> n;
    long long l = 1, r = 0;
    vector<int> lan(k,0);
    for(int i = 0; i < k; i++){
        cin>>lan[i];
        if(r<lan[i])r=lan[i];//가장 긴 랜설의 길이로 r을 설정
    }

    while(l<=r){
        mid = (l+r)/2;
        long long sum = 0;
        for(int i = 0; i < k; i++){
            sum+=lan[i]/mid;
        }

        if(sum>=n){
            ans = mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << ans;
}