#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int parent[51];

int find(int a){
    if(parent[a]==a)return a;
    return parent[a]=find(parent[a]);
}

void unionFind(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b) parent[a]=b;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, x, tmp, kp=0, cnt=0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)parent[i]=i;
    cin >> x;
    if(x>0){
        cin >> kp;
        for(int i = 1; i < x; i++){
            cin >> tmp;
            unionFind(kp, tmp);
        }
    }
    vector<int> tp(m);
    for(int i = 0; i < m; i++){
        cin >> x;
        cin >> tp[i];
        for(int j = 1; j < x; j++){
            cin >> tmp;
            unionFind(tp[i], tmp);
        }
    }

    for(int i = 0; i < m; i++){
        if(find(kp) != find(tp[i]))cnt++;
    }

    cout << cnt;
}