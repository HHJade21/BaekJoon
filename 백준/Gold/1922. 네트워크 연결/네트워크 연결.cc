#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n, m, cnt=0,a,b,c, p[1001],ans=0;

int find(int x){
    if(p[x]==x)return x;
    else return p[x]=find(p[x]);
}

void unionP(int x, int y){
    x=find(x);
    y=find(y);

    p[x]=y;
}

struct e{
    int v1;
    int v2;
    int w;
};

struct cmp{
    bool operator()(e a, e b){
        return a.w>b.w;
    }
};

priority_queue<e, vector<e>, cmp> q;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    vector<bool> vis(n+1,0);

    for(int i = 1; i <=n; i++)p[i]=i;

    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        
        if(a==b)continue;

        q.push({a,b,c});
    }

    while(q.size()){
        int now1 = q.top().v1, now2 = q.top().v2, nw=q.top().w;
        q.pop();
        if(find(now1)==find(now2))continue;
        ans+=nw;
        unionP(now1, now2);
    }
    cout<<ans;
}