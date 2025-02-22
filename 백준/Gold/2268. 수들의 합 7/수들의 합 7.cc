#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<long long>arr(1000001,0);
vector<long long>tree;
long long n,m,a,b,c;

long long sum(int node, int st, int ed, int l, int r){
    if(ed<l || r<st)return 0;
    if(l<=st && ed<=r)return tree[node];
    return sum(node*2, st, (st+ed)/2, l, r) + sum(node*2+1, (st+ed)/2+1, ed, l,r);
}

void update(int node, int st, int ed, int idx, long long diff){
    if(idx<st || ed<idx)return;
    tree[node]+=diff;
    if(st!=ed){
        update(node*2, st, (st+ed)/2, idx, diff);
        update(node*2+1, (st+ed)/2+1, ed, idx, diff);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    tree=vector<long long>(n*4,0);

    for(int i = 0; i<m; i++){
        cin>>a>>b>>c;

        if(a){//update
            long long diff = c-arr[b];
            arr[b]=c;
            update(1,1,n,b,diff);
        }
        else{//sum
            if(b>c)swap(b,c);
            cout << sum(1,1,n,b,c)<<"\n";
        }
    }
}