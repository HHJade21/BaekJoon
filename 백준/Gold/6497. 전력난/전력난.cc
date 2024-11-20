#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int t, n, m,x,y,z, p[200000]={0,},ans,sum;
struct e{
    int sv;
    int ev;
    int w;
};

struct cmp{
    bool operator()(e a, e b){
        return a.w>b.w;
    }
};

priority_queue<e, vector<e>, cmp> pq;

int Find(int x){
    if(p[x]==x)return x;
    else return p[x]=Find(p[x]);
}

void UF(int x, int y){
    x=Find(x);
    y=Find(y);
    p[x]=y;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    while(true){
        cin>>n>>m;
        if(n==0&&m==0)return 0;
        vector<bool>vis(n,0);
        for(int i = 0; i < n; i++)p[i]=i;
        pq={};
        ans=0;
        sum=0;

        while(m--){
            cin>>x>>y>>z;
            pq.push({x,y,z});
            sum+=z;
        }

        while(pq.size()){
            int v1 = pq.top().sv, v2 = pq.top().ev, weight = pq.top().w;
            pq.pop();
            if(Find(v1)==Find(v2))continue;
            UF(v1,v2);
            ans+=weight;
        }
        cout<<sum-ans << "\n";
    }

}