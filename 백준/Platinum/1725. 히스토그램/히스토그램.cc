#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>left(n);
    vector<int>right(n);
    stack<pair<int,int>>st;//높이, 인덱스
    for(int i = 0; i < n;i++){
        cin>>arr[i];
        while(st.size()&&st.top().first>=arr[i])st.pop();
        if(st.empty())left[i]=0;
        else left[i]=st.top().second+1;
        st.push({arr[i],i});
    }
    st={};
    for(int i = n-1; i>=0; i--){
        while(st.size()&&st.top().first>=arr[i])st.pop();
        if(st.empty())right[i]=n-1;
        else right[i] = st.top().second-1;
        st.push({arr[i],i});
    }
    int ans = 0;
    for(int i =0;i<n;i++){
        ans = max(ans, (right[i]-left[i]+1)*arr[i]);
    }
    cout<<ans;
}