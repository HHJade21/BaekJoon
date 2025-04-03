#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s, tmp;
    int t,n;
    cin>>t;
    while(t--){
        vector<int>cnt(26,0);
        cin>>s;
        for(auto i : s){
            cnt[i-'A']++;
        }
        cin>>n;
        while(n--){
            cin>>tmp;
            vector<int>tmpcnt = cnt;
            bool can = true;
            for(auto i : tmp){
                if(!tmpcnt[i-'A']){
                    can = false;
                    break;
                }
                else{
                    tmpcnt[i-'A']--;
                }
            }
            if(can)cout<<"YES\n";
            else cout << "NO\n";
        }
    }
}