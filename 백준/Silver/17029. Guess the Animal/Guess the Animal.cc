#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m,cnt,ans=0;
    cin >> n;
    string tmp;
    vector<set<string>> w(n, set<string>());
    for(int i = 0; i < n; i++){
        cin>>tmp;
        cin>>m;
        for(int j = 0; j < m; j++){
            cin>>tmp;
            w[i].insert(tmp);
        }

        for(int j = 0; j < i; j++){
            auto it = w[i].begin();
            cnt=0;

            for(int k = 0; k < m; k++){
                if(w[j].find(*it)!=w[j].end()){
                    cnt++;
                }
                
                it++;
            }
            if(cnt>ans)ans=cnt;
        }
    }
    cout<<ans+1;
}