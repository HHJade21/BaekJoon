#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
bool cmp(pair<int,int>a, pair<int,int>b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m,tmp;
    cin>>n;
    vector<pair<int,int>>a;
    vector<pair<int,int>>b;
    for(int i = 1; i <= n; i++){
        cin>>tmp;
        a.push_back({tmp,i});
    }
    cin>>m;
    for(int i = 1; i <= m; i++){
        cin>>tmp;
        b.push_back({tmp,i});
    }
    sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end(),cmp);

    int ai=0,bi=0,lasta=0, lastb=0,cnt=0;
    vector<int>ans;
    while(ai<n&&bi<m){
        if(a[ai].second<lasta)ai++;
        else if(b[bi].second<lastb)bi++;
        else if(a[ai].first==b[bi].first){
            cnt++;
            ans.push_back(a[ai].first);
            lasta = a[ai++].second;
            lastb = b[bi++].second;
        }
        else if(a[ai].first<b[bi].first)bi++;
        else ai++;
    }
    cout<<cnt<<"\n";
    for(auto i : ans)cout<<i<<" ";
}