#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

struct node{
    int value;
    int idx;
};

struct cmp{
    bool operator()(node a, node b){
        if(a.value == b.value)return a.idx>b.idx;
        return a.value>b.value;
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    priority_queue<node,vector<node>,cmp>pq;
    int n,cmd,id,v,m;
    cin>>n;
    vector<int>arr(n+1);
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
        pq.push({arr[i],i});
    }
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>cmd;
        if(cmd==1){
            cin>>id>>v;
            pq.push({v,id});
            arr[id]=v;
        }
        else{
            while(arr[pq.top().idx] != pq.top().value)pq.pop();
            cout<<pq.top().idx << "\n";
        }
    }
}