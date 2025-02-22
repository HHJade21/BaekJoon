#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<long long>arr;
vector<long long>tree;
long long n,m,k,a,b,c;

long long init(int node, int start, int end){
    if(start==end) return tree[node]=arr[start];
    return tree[node]=(init(node*2, start, (start+end)/2)*init(node*2+1, (start+end)/2+1, end))%1000000007;
}

long long mult(int node, int start, int end, int left, int right){
    if(right<start || end < left)return 1;
    if(left <= start && end <= right)return tree[node];
    //이제 애매하게 쪼개져 있는 경우
    return (mult(node*2,start,(start+end)/2,left,right)*mult(node*2+1,(start+end)/2+1, end,left,right))%1000000007;
}

void update(int node, int start, int end, int idx, int value){
    if(idx<start || end<idx)return;
    if(start==end){
        tree[node]=value;
        return;
    }

    update(node*2, start, (start+end)/2, idx, value);
    update(node*2+1, (start+end)/2+1, end, idx, value);

    tree[node]=(tree[node*2]*tree[node*2+1])%1000000007;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>k;
    arr=vector<long long>(n+1);
    tree=vector<long long>(n*4);
    for(int i = 1; i <=n; i++)cin>>arr[i];
    init(1,1,n);
    for(int i = 0 ; i < m+k; i++){
        cin>>a>>b>>c;
        if(a==1){//b번째 수를 c로 바꿈
            update(1,1,n,b,c);
        }
        else{//b부터c까지의 구간곱 출력
            cout << mult(1,1,n,b,c) << "\n";
        }
    }
}