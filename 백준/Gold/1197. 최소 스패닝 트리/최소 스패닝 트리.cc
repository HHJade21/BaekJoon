#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
    int s;
    int e;
    int w;
};

struct cmp{
    bool operator()(node a, node b){
        if(a.w == b.w) {
            if(a.e==b.e) return a.s<b.s;
            return a.e < b.e;
        }
        else return a.w > b.w;
    }
};


priority_queue<node, vector<node>, cmp> pq;
vector<bool> visit(10001, 0);
vector<int> p(10001, 0);

int findp(int a){
    int x;
    if(p[a]==a) return a;
    p[a]=findp(p[a]);
    return p[a];
}


void unionp(int a, int b){
    int pa=findp(a);
    int pb=findp(b);
    if(pa==pb) return;

    p[pa]=pb;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int v, e, start, end, weight, sum = 0, t1, t2;

    cin >> v >> e;
    
    for(int i = 0; i < e; i++){
        cin >> start >> end >> weight;
        pq.push({start, end, weight});
    }
    for(int i = 1; i <= v; i++) p[i] = i;

    while(!pq.empty()){
        t1 = pq.top().s;
        t2 = pq.top().e;
        weight = pq.top().w;
        pq.pop();
        
        if(visit[t1] && visit[t2] && findp(t1)==findp(t2)) continue;
        //test code
        //cout << t1 << " to " << t2 << ". weight : " << weight << "\n";
        unionp(t1, t2);
        visit[t1] = true;
        visit[t2] = true;
        sum += weight;
    }

    cout << sum;


}