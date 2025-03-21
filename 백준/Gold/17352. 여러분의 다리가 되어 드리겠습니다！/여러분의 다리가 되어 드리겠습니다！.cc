#include<iostream>
using namespace std;
int n,a,b;
int p[300001];
int find(int x){
    if(p[x]==x)return x;
    return p[x] = find(p[x]);
}
void unionfind(int x, int y){
    x = find(x);
    y = find(y);
    p[y]=x;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i = 1; i <=n ;i++)p[i]=i;
    for(int i = 1; i < n; i++){
        cin>>a>>b;
        unionfind(a,b);
    }
    a=find(1);
    for(int i = 1; i <=n; i++){
        if(find(i)!=a)b=find(i);
    }
    cout << a << " " << b;
}