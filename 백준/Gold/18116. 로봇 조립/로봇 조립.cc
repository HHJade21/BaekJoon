#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int p[1000001],q[1000001],n,a,b;
char c;

int find(int x){
    if(p[x]==x)return x;
    return p[x]=find(p[x]);
}

void unioon(int x, int y){
    x = find(x);
    y = find(y);

    q[x]+=q[y];//부품수 합쳐주기
    p[y]=x;//x를 부모로
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;

    //p,q초기화
    for(int i = 1; i <=1000000;i++){
        p[i]=i;
        q[i]=1;
    }

    for(int i = 0 ;i < n;i++){
        cin>>c;
        if(c=='I'){
            cin>>a>>b;
            if(find(a)!=find(b))unioon(a,b);
        }
        else{
            cin>>a;
            cout<<q[find(a)]<<"\n";
        }
    }
}