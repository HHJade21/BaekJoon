#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int dp[40001]={1,},n,m,gu,chu;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>chu;
        for(int j = 15000; j>=chu; j--){
            if(dp[j-chu])dp[j]=1;
        }
    }
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>gu;
        bool can = false;
        for(int j = gu; j<=15000; j++){
            if(!dp[j])continue;
            if(dp[j-gu]){
                can=true;
                break;
            }
        }
        if(can)cout<<"Y ";
        else cout<<"N ";
    }

}