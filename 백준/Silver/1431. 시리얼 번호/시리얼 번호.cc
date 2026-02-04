#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<string>
using namespace std;

struct st{
    int len;
    string s;
};

bool cmp(st a, st b){
    if(a.len==b.len){
        int aa=0,bb=0;
        for(auto c : a.s){
            if('0'<=c && c<= '9')aa+=c-'0';
        }
        for(auto c : b.s){
            if('0'<=c && c<= '9')bb+=c-'0';
        }
        if(aa==bb)return a.s<b.s;
        return aa<bb;
    }
    return a.len<b.len;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    string tmp;
    cin>>n;
    vector<st> v;
    for(int i = 0; i < n;i++){
        cin>>tmp;
        v.push_back({tmp.size(),tmp});
    }
    sort(v.begin(),v.end(),cmp);

    for(auto i : v){
        cout<<i.s<<"\n";
    }
}