#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<int>arr;
vector<int>tree;
int n,k,x,a,b;
char c;

int init(int node, int s, int e){
    if (s==e)return tree[node]=arr[s];
    return tree[node]=init(node*2, s, (s+e)/2)*init(node*2+1,(s+e)/2+1, e);
}

int mult(int node, int s, int e, int l, int r){
    if(e<l || r<s)return 1;
    if(l<=s && e<=r)return tree[node];
    return mult(node*2, s, (s+e)/2, l,r) * mult(node*2+1, (s+e)/2+1, e, l,r);
}

void update(int node, int s, int e, int idx, int value){
    if(idx<s || idx>e)return;
    if(s==e)tree[node]=value;
    else{
        update(node*2, s, (s+e)/2, idx, value);
        update(node*2+1, (s+e)/2+1, e, idx, value);
        tree[node]=tree[node*2]*tree[node*2+1];
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    while(cin>>n>>k){
        arr=vector<int>(n+1,0);
        tree=vector<int>(n*4,0);
        for(int i = 1; i <=n; i++){
            cin>>x;
            if(x<0)arr[i]=-1;
            else if(x>0)arr[i]=1;
            else arr[i]=0;
        }
        init(1,1,n);

        for(int i = 0; i < k; i++){
            cin>>c>>a>>b;
            if(c=='C'){//변경
                if(b<0)b=-1;
                else if(b>0)b=1;
                else b=0;
                arr[a]=b;
                update(1,1,n,a,b);
            }
            else{//곱셈
                int res = mult(1,1,n,a,b);
                if(res>0)cout<<'+';
                else if(res<0)cout<<'-';
                else cout<<0;
            }
        }
        cout<<"\n";
    }
}