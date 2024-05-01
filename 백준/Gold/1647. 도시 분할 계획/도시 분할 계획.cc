#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, start, dest, weight, ans=0;
bool visit[100001]={0,};

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

int parent[100001];

int findP(int a){
    if(parent[a] == a) return a;

    parent[a] = findP(parent[a]);
    return parent[a];
}

void unionP(int a, int b){
    int pa = findP(a), pb = findP(b);
    if(pa==pb) return;
    parent[pa]=pb;
}


priority_queue<node, vector<node>, cmp> pq;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> start >> dest >> weight;
        pq.push({start, dest, weight});
    }

    for(int i = 1; i <=n; i++) {
        parent[i]=i;
    }


    //test code
    //cout << "pq.top() : " << pq.top().s << " " << pq.top().e << " " << pq.top().w << "\n";

    while(n>2){
        int tx = pq.top().s, ty = pq.top().e, tw = pq.top().w, tpx = findP(tx), tpy = findP(ty);
        pq.pop();
        if(tpx == tpy)continue;


        //test code
        //cout << "tx , ty, tw : " << tx << ", " << ty << ", " << tw << "\n";


        unionP(tx, ty);
        n--;
        ans+=tw;
    }

    cout << ans;
}