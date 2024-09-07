#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

struct kang{
    int a;
    int b;
    int c;
};

bool abCmp(kang p, kang q){
    return p.a+p.b > q.a+q.b;
}

bool bcCmp(kang p, kang q){
    return p.c+p.b > q.c+q.b;
}

bool acCmp(kang p, kang q){
    return p.a+p.c > q.a+q.c;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, k, sum=0, ans = 0;

    cin >> n >> k;
    vector<kang> su(n);
    for(int i = 0; i < n; i++)
    {
        cin >> su[i].a >> su[i].b >> su[i].c;
    }

    sort(su.begin(), su.end(), abCmp);
    for(int i  = 0; i < k; i++){
        sum+=su[i].a+su[i].b;
    }
    if(ans<sum)ans=sum;

    sum=0;
    sort(su.begin(), su.end(), bcCmp);
    for(int i  = 0; i < k; i++){
        sum+=su[i].c+su[i].b;
    }
    if(ans<sum)ans=sum;

    sum=0;
    sort(su.begin(), su.end(), acCmp);
    for(int i  = 0; i < k; i++){
        sum+=su[i].c+su[i].a;
    }
    if(ans<sum)ans=sum;

    cout << ans;
}