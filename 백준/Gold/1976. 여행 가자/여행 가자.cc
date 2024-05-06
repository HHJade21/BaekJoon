#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int parent[201]={0,};

int find(int a){
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}

void unionFind(int a, int b){
    a = find(a);
    b=find(b);
    if(a!=b) parent[a]=b;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, x;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)parent[i]=i;

    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            if(i<j && x) unionFind(i, j);
        }
    }

    int start;
    bool success= true;
    cin >> start;
    start=find(start);
    for(int i = 1; i < m; i++){
        cin >> x;
        if(find(x)==start)continue;
        success = false;
        break;
        
    }

    if(success)cout << "YES";
    else cout << "NO";
}