#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>a(n,0);
    vector<int>b;
    for(int i = 0; i < n; i++)cin>>a[i];
    for(int i = 0; i < n; i++){
        if(b.empty()||b.back()<a[i])b.push_back(a[i]);
        else b[lower_bound(b.begin(), b.end(), a[i])-b.begin()]=a[i];
    }
    cout<<b.size();
}