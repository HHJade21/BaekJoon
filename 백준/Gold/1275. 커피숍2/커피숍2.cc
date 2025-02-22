#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<long long>arr;
vector<long long>tree;
long long n,q,x,y,a,b;

long long init(int node, int st, int ed){
    if(st==ed)return tree[node]=arr[st];
    return tree[node]=init(node*2, st, (st+ed)/2) + init(node*2+1, (st+ed)/2+1,ed);
}

long long sum(int node, int st, int ed, int l, int r){
    if(ed<l || r<st)return 0;
    if(l<=st && ed<=r)return tree[node];
    return sum(node*2,st,(st+ed)/2,l,r) + sum(node*2+1, (st+ed)/2+1, ed,l,r);
}

void update(int node, int st, int ed, int idx, long long diff){
    if(idx<st || ed<idx)return;
    tree[node]+=diff;
    if(st!=ed){
        update(node*2, st, (st+ed)/2, idx,diff);
        update(node*2+1, (st+ed)/2+1, ed, idx, diff);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>q;
    arr = vector<long long>(n+1,0);
    tree=vector<long long>(n*4,0);
    for(int i = 1; i <=n; i++){
        cin>>arr[i];
    }
    init(1,1,n);

    while(q--){
        cin>>x>>y>>a>>b;//x~y 구간합을 구하고 a번째 수를 b로 바꾸기
        if(x>y)swap(x,y);
        cout << sum(1,1,n,x,y)<<"\n";
        long long diff = b-arr[a];
        arr[a]=b;
        update(1,1,n,a,diff);
    }
}