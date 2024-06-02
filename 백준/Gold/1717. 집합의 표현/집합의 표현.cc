#include <iostream>
#include<vector>

using namespace std;
int n, m, command, a, b;
vector<int> parent;


int find(int v){
    if(parent[v] == v) return v;
    
    else return parent[v]=find(parent[v]);
}

void unionF(int x, int y){
    x = find(x);
    y = find(y);
    if(x!=y) parent[y] = x;
    
}

bool checkSame(int x, int y){
    x = find(x);
    y = find(y);
    return (x == y);
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >>m;
    parent = vector<int>(n+1, 0);
    for(int i = 1; i <= n; i++) parent[i]=i;
    for(int i = 0; i < m; i++){
        cin >> command >> a >> b;
        if(command){
            if(checkSame(a,b)){
                cout <<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            unionF(a, b);
        }
    }

    return 0;
}