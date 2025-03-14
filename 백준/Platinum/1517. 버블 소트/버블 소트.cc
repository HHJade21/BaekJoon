#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<pair<int,int>>arr;//first : value, second : index
vector<int>tree;//tree[node] (구간i~j) : 배열의 i번째 숫자부터 j번째 숫자까지 중에서 지금까지 처리된 것의 개수
int n;
long long ans=0;

void update(int node, int s, int e, int idx){
    if(s==e){
        tree[node]=1;
        return;
    }
    int mid = (s+e)/2;
    if(idx<=mid)update(node*2,s,mid,idx);//idx가 왼쪽 구간에 있으면 왼쪽만 새로 업데이트
    else update(node*2+1, mid+1, e, idx);//오른쪽 구간에 있으면 오른쪽만 새로 업데이트
    tree[node]=tree[node*2]+tree[node*2+1];//양쪽의 구간합으로 갱신
}

long long cnt(int node, int s, int e, int l, int r){
    if(e<l || r<s)return 0;
    if(l<=s && e<=r)return tree[node];
    return cnt(node*2, s, (s+e)/2,l,r) + cnt(node*2+1, (s+e)/2+1, e, l, r);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    arr = vector<pair<int,int>>(n+1);
    tree=vector<int>(n*4,0);
    for(int i = 1; i <= n; i++){
        cin>>arr[i].first;//value를 first로 해주는 이유 : value가 낮은 애부터 세그먼트트리에 넣어야 하기 때문에
        arr[i].second=i;
    }
    sort(arr.begin()+1, arr.end());

    for(int i = 1; i <=n; i++){
        ans += cnt(1,1,n,arr[i].second+1, n);//다음 최솟값을 넣기 전에, 걔보다 작은 숫자 중 idx번째보다 뒤에 있는 애들을 답에 합산
        update(1,1,n,arr[i].second);//다음 최솟값을 idx번째로 넣고, 세그먼트트리에 반영
    }
    cout<<ans;
}