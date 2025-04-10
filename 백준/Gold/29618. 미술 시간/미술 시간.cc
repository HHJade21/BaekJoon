#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int a,b,x,n,q,p[100001],color[100001];

int find(int x){
    if(p[x]==x)return x;
    return p[x]=find(p[x]);
}

void unioon(int x, int y){
    x=find(x);
    y=find(y);
    if(x>y)swap(x,y);//x가 작도록 맞춰주기
    p[x]=y;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>q;
    for(int i = 1; i <= n; i++)p[i]=i;
    while(q--){
        cin>>a>>b>>x;
        for(int i = a; i<=b; i++){
            if(color[i-1])unioon(i-1, i);
            if(color[i])i=find(i);
            else color[i]=x;
        }
    }
    for(int i = 1; i<=n; i++) cout << color[i] << " ";
}