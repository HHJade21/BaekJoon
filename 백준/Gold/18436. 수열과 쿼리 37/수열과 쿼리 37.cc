#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<long long>arr;
vector<pair<int, int>>tree;//짝수의 개수, 홀수의 개수
long long n,m,tmp,a,b,c;

pair<int,int> init(int node, int s, int e){
    if(s==e){
        if(arr[s]%2)tree[node].second=1;
        else tree[node].first=1;
        return tree[node];
    }
    pair<int,int> t1 = init(node*2, s, (s+e)/2);
    pair<int,int> t2 = init(node*2+1, (s+e)/2+1, e);
    return tree[node] = {t1.first+t2.first, t1.second+t2.second};
}

pair<int,int> sum(int node, int s, int e, int l, int r){
    if(e<l || r<s)return {0,0};
    if(l<=s && e<=r)return tree[node];
    pair<int,int> t1 = sum(node*2, s, (s+e)/2, l,r);
    pair<int,int> t2 = sum(node*2+1, (s+e)/2+1, e, l, r);
    return {t1.first+t2.first, t1.second+t2.second};
}

//value가 0이면 짝수+1홀수-1, 1이면 짝수-1홀수+1
void update(int node, int s, int e, int idx, int value){
    if(idx<s || e<idx)return;
    if(value){
        tree[node].first--;
        tree[node].second++;
    }
    else{
        tree[node].first++;
        tree[node].second--;
    }
    if(s!=e){
        update(node*2, s, (s+e)/2, idx, value);
        update(node*2+1, (s+e)/2+1, e, idx, value);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    arr.resize(n+1,0);
    tree.resize(4*n,{0,0});
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }
    cin>>m;
    init(1,1,n);

    while(m--){
        cin>>a>>b>>c;
        if(a==1){//b번째 수를 c로 바꾸기
            if(arr[b]%2 != c%2){
                arr[b]=c;
                update(1,1,n,b,c%2);
            }
        }
        else if(a==2){//b~c 구간 내 짝수의 개수 출력
            cout << sum(1,1,n,b,c).first << "\n";
        }
        else{//b~c구간 내 홀수의 개수 출력
            cout << sum(1,1,n,b,c).second << "\n";
        }
    }
}