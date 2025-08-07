#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n,m,k,p,q;

struct a{
    int p;//집합의 부모
    int size;//집합의 사람수
    int candy;//집합의 사탕수
};
vector<a>kid(30001);
vector<int>dp(3000,0);

int find(int x){
    if(kid[x].p == x)return x;
    return kid[x].p=find(kid[x].p);
}

void unioon(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y)return;
    kid[y].p=x;//x를 부모로
    kid[x].size+=kid[y].size;//사람수 합치기
    kid[x].candy+=kid[y].candy;//사탕수 합치기
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i = 1 ; i <= n; i++){
        cin>>kid[i].candy;
        kid[i].size=1;
        kid[i].p=i;
    }
    for(int i = 0; i < m; i++){
        cin>>p>>q;
        unioon(p,q);
    }
    for(int i = 1; i<=n; i++){
        if(find(i)!=i)continue;//자기 자신이 부모인 경우만 체크
        int ksize=kid[i].size;
        int kcandy=kid[i].candy;
        for(int j = k-1; j>=ksize; j--){
            dp[j] = max(dp[j], dp[j-ksize]+kcandy);
        }
    }
    cout<<dp[k-1];
}