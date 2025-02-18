#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>a(n);
    vector<char>ans;
    for(int i = 0 ; i < n; i++)cin>>a[i];

    stack<int>st;
    int idx=0;
    for(int i = 1 ; i <= n; i++){
        if(a[idx]>=i){
            ans.push_back('+');
            st.push(i);
        }
        else{
            cout << "NO";
            return 0;
        }
        while(st.size() && a[idx]==st.top()){
            ans.push_back('-');
            st.pop();
            idx++;
        }
    }
    if(idx<n){
        cout << "NO";
        return 0;
    }
    else{
        for(auto i : ans)cout << i << "\n";
    }
}
