#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<map>
using namespace std;


bool cmp(pair<string, int> a, pair<string, int> b){
    if(a.second == b.second){
        if(a.first.size() == b.first.size()){
            for(int i = 0; i < a.first.size(); i++){
                if(a.first[i]==b.first[i])continue;
                if(a.first[i]<b.first[i])return true;
                return false;
            }
        }
        return a.first.size()>b.first.size();
    }
    return a.second>b.second;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;
    string s;
    cin >> n >> m;

    map<string, int> w;

    for(int i = 0; i < n; i++){
        cin>>s;
        if(s.size()<m)continue;

        auto it = w.find(s);

        if(it==w.end()){//처음 등장한 경우
            w.insert({s, 0});
        }
        else{//기존에 존재하던 단어인 경우
            it->second++;
        }
    }
    
    vector<pair<string, int>> a;

    for(auto i : w){
        a.push_back({i.first, i.second});
    }

    //test code
    // for(auto i : a){
    //     cout << i.first << " : " << i.second << "\n";
    // }
    // cout<<"\n\n\n";

    sort(a.begin(), a.end(), cmp);

    for(auto i : a){
        cout << i.first << "\n";    
    }
}