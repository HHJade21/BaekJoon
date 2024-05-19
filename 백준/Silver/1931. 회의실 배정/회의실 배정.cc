#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

bool cmp(pair<int,int>a, pair<int,int>b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n,e;
    cin >> n;
    vector<pair<int,int>> hoi(n);
    for(int i = 0; i < n; i++){
        cin >> hoi[i].first >> hoi[i].second;
    }
    sort(hoi.begin(),hoi.end(),cmp);

    int cnt = 1;
    e = hoi[0].second;


    for(int i = 1; i < n; i++){
        if(hoi[i].first>=e){
            cnt++;
            e=hoi[i].second;
        }
    }

    cout << cnt;
}