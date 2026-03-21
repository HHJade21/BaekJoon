#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,d,k,c, ans=0, tmp=0,l=0;
    cin>>n>>d>>k>>c;
    vector<int>v(n);
    vector<int>cnt(d+1,0);

    for(int i = 0; i < n ; i++){
        cin>>v[i];
    }

    for(int r = 0; r < n*2; r++){
        if(cnt[v[r%n]] == 0){
            tmp++;
        }
        cnt[v[r%n]]++;
        if(r-l >=k){
            cnt[v[l%n]]--;
            if(cnt[v[l%n]] == 0) {
                tmp--;
            }
            l++;
        }
        if(cnt[c])ans = max(ans, tmp);
        else ans = max(ans, tmp+1);
    }
    cout<<ans;
}