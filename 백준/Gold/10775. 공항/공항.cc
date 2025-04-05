#include<iostream>
using namespace std;
int p[100001]={0,};
int Find(int x){
    if(p[x]==x)return x;
    return p[x] = Find(p[x]);
}
void unionF(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a!=b){//작은 쪽을 부모로 만들어주기
        if(a<b) p[b]=a;
        else p[a]=b;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int g, n, x,ans=0;
    for(int i = 1; i < 100001; i++) p[i] = i;
    cin>>g>>n;
    while(n--){
        cin>>x;
        if(Find(x)==0) break;
        ans++;
        unionF(Find(x), Find(x)-1);
    }
    cout<<ans;
}