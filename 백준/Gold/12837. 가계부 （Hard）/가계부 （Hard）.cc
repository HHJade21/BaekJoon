#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<long long>arr;
vector<long long>tree;
long long n,q,c,x,y;

long long sum(int node, int s, int e, int l, int r){
    if(e<l || r<s)return 0;
    if(l<=s && e<=r)return tree[node];
    return sum(node*2, s, (s+e)/2, l, r) + sum(node*2+1, (s+e)/2+1, e, l, r);
}

void update(int node, int s, int e, int idx, long long diff){
    if(idx<s || e<idx)return;
    tree[node]+=diff;
    if(s!=e){
        update(node*2, s, (s+e)/2, idx, diff);
        update(node*2+1, (s+e)/2+1, e, idx, diff);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>q;
    arr=vector<long long>(n+1,0);
    tree=vector<long long>(n*4,0);
    for(int i = 0; i < q; i++){
        cin>>c>>x>>y;
        if(c==1){//x번 인덱스에 y 추가
            arr[x]+=y;
            update(1,1,n,x,y);
        }
        else{//x~y 구간합 출력하고 줄바꿈
            cout << sum(1,1,n,x,y) << "\n";
        }
    }
}