#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0 ; i < n; i++)cin>>a[i];
    vector<int>ans;
    for(int i : a){
        if(ans.empty() || ans.back() < i) ans.push_back(i);
        else ans[lower_bound(ans.begin(), ans.end(), i) - ans.begin()]=i;
    }
    cout<<ans.size();
}