#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

//두 정점 사이에 "최소 가중치가 k인 경로가 존재한다" => 이때 k의 최댓값은?
//1. 두 정점 사이 경로의 가중치들 정렬.... 불가능
//매개변수 탐색 => mid 이상인 간선에 대해서만 union하기. 
//for문 종료 후 v1, v2가 연결되어 있으면 left=m+1 하고 ans 갱신
//연결되어 있지 않으면 right=mid-1

struct edge{
    int s;
    int e;
    int w;
};

vector<edge>g;
vector<int>p;//매개변수탐색하면서 계속 초기화되는 애
vector<int>pp;//1234567...고정

int n,m,ans=0,a,b,c,l,r,mid, v1, v2;

int find(int x){
    if(p[x]==x)return x;
    return p[x]=find(p[x]);
}

void onion(int x, int y){
    x = find(x);
    y = find(y);
    p[x]=y;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i = 0 ;i <  m; i++){
        cin>>a>>b>>c;
        g.push_back({a,b,c});
        l = min(c,l);
        r = max(c,r);
    }

    pp=vector<int>(n+1);
    for(int i = 1; i<=n; i++){
        pp[i]=i;
    }

    cin>>v1>>v2;

    while(l<=r){
        mid = (l+r)/2;
        p = pp;//p배열 초기화(1,2,3,4..)
        for(int i = 0 ; i < m; i++){
            if(g[i].w >= mid && find(g[i].s) != find(g[i].e)){
                onion(g[i].s, g[i].e);
            }
        }
        if(find(v1)==find(v2)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout<<ans;
}