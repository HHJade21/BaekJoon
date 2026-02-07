#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    vector<int>v;
    int n,ans=0,tmp;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>tmp;
        v.push_back(tmp);
    }

    while(v.size()){
        bool div=0;
        for(int i = 0; i < v.size(); i++){
            if(v[i]%2==1){
                v[i]--;
                ans++;
            }
            if(v[i]>1){
                v[i]/=2;
                div=true;
            }
            if(v[i]==0){
                v.erase(v.begin()+i);
                i--;
            }
        }
        if(div)ans++;
    }
    cout<<ans;
}