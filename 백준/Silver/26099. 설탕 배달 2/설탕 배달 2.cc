#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long sugar, ans=0;
    cin>>sugar;
    ans = sugar/5;
    if(sugar%5==0);
    else if(sugar%5==1){
        if(ans>0)ans++;
        else ans=-1;
    }
    else if(sugar%5==2){
        if(ans>1) ans+=2;
        else ans = -1;
    }
    else if(sugar%5==3){
        ans++;
    }
    else{
        if(ans>0)ans+=2;
        else ans = -1;
    }
    cout<<ans;
}