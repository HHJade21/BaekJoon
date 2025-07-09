#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

vector<int>p;
int find(int x){
    if(p[x]==x)return x;
    return p[x]=find(p[x]);
}
void onion(int x, int y){
    x=find(x);
    y=find(y);
    p[x]=y;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){
        int n,m,a,b;
        cin>>n>>m;
        p = vector<int>(n+1,0);
        for(int j=1;j<=n;j++)p[j]=j;

        for(int j = 0; j<m;j++){
            cin>>a>>b;
            onion(a,b);
        }
        cin>>m;
        cout<<"Scenario " << i << ":\n";
        for(int j = 0; j<m;j++){
            cin>>a>>b;
            if(find(a)==find(b))cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        cout<<"\n";
    }
}