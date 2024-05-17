#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

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
priority_queue<node, vector<node>, cmp> edge;

vector<int>parent;

int Find(int a){
    if(parent[a]==a)return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
    int pa = Find(a), pb = Find(b);
    parent[pa]=pb;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    

    string s;
    int n, sum = 0;
    cin >> n;
    parent = vector<int>(n,0);
    for(int i = 0; i < n; i++)parent[i]=i;
    for(int i = 0; i < n; i++){
        cin>>s;
        for(int j = 0; j < n; j++){
            if(s[j]=='0')continue;

            if(s[j]>='a'&&s[j]<='z') {
                edge.push({i,j,s[j]-'a'+1});
                sum += s[j]-'a'+1;
            }
            else if(s[j]>='A'&&s[j]<='Z') {
                edge.push({i,j,s[j]-'A'+27});
                sum += s[j]-'A'+27;
            }
        }
    }

    while(!edge.empty()){
        int start = edge.top().s, end = edge.top().e, weight = edge.top().w;
        edge.pop();
        if(Find(start)==Find(end))continue;
        Union(start, end);
        sum-=weight;
        n--;
    }

    if(n>1) cout << -1;
    else cout << sum;
}