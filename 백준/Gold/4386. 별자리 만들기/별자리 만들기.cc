#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<cmath>
using namespace std;

struct node{
    int s;
    int e;
    double w;
};

struct cmp{
    bool operator()(node a, node b){
        return a.w>b.w;
    }
};

vector<int> parent;


int find(int a){
    if(parent[a]==a) return a;
    return parent[a]=find(parent[a]);
}

void unionFind(int a, int b){
    int pa = find(a), pb = find(b);
    if(pa!=pb) parent[pa]=pb;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    double sum = 0;
    cin >> n;

    vector<pair<double, double>> stars(n);
    for(int i = 0; i < n; i++) cin >> stars[i].first >> stars[i].second;

    priority_queue<node, vector<node>, cmp> q;

    parent = vector<int>(n, 0);
    for(int i = 0; i<n; i++)parent[i]=i;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            double weight = sqrt((stars[i].first-stars[j].first)*(stars[i].first-stars[j].first) + (stars[i].second-stars[j].second)*(stars[i].second-stars[j].second));
            q.push({i, j, weight});
        }
    }

    while(q.size()){
        int ta = q.top().s, tb = q.top().e;
        double tw = q.top().w;
        q.pop();
        int pa = find(ta), pb = find(tb);
        if(pa == pb)continue;

        unionFind(ta, tb);
        sum += tw;
    }

    printf("%.2lf", sum);
}