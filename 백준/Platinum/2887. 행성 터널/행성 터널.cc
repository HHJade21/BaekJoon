#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

struct planet{
    int idx;
    int x;
    int y;
    int z;
};
vector<planet> star;

struct node{
    int s;
    int e;
    int w;
};

struct cmp{
    bool operator()(node a, node b){
        return a.w>b.w;
    }
};

priority_queue<node, vector<node>,cmp> pq;

vector<int> parent;

int Find(int a){
    if(parent[a]==a)return a;
    else return parent[a]=Find(parent[a]);
}

void Union(int a, int b){
    int pa=Find(a), pb = Find(b);
    parent[pa]=pb;
}

bool xcmp(planet a, planet b){
    return a.x<b.x;
}

bool ycmp(planet a, planet b){
    return a.y < b.y;
}

bool zcmp(planet a, planet b){
    return a.z<b.z;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, a, b, c;
    long long ans = 0;
    cin >> n;
    parent = vector<int>(n,0);
    for(int i = 0; i < n; i++)parent[i]=i;

    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        star.push_back({i,a,b,c});
    }

    sort(star.begin(), star.end(), xcmp);
    for(int i = 1; i < n; i++) pq.push({star[i-1].idx, star[i].idx, star[i].x - star[i-1].x});
    
    sort(star.begin(), star.end(), ycmp);
    for(int i = 1; i < n; i++) pq.push({star[i-1].idx, star[i].idx, star[i].y - star[i-1].y});

    sort(star.begin(), star.end(), zcmp);
    for(int i = 1; i < n; i++) pq.push({star[i-1].idx, star[i].idx, star[i].z - star[i-1].z});


    while(pq.size()){
        int ta = pq.top().s, tb = pq.top().e, tw = pq.top().w;
        pq.pop();
        int pa = Find(ta), pb = Find(tb);
        if(pa == pb)continue;
        Union(pa, pb);
        ans+=tw;
    }

    cout << ans;
}