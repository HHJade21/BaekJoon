#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,tmp;
    cin>>n;
    while(n){
        long long arr[n];
        int left[n], right[n];
        stack<pair<int,int>>st;

        st.push({-1,-1});

        for(int i = 0; i < n; i++){
            cin>>arr[i];
            if(arr[i] > st.top().first){
                left[i] = i;
                st.push({arr[i], i});
                continue;
            }
            while(arr[i]<=st.top().first)st.pop();
            left[i] = st.top().second+1;
            st.push({arr[i],i});
        }
        st={};
        st.push({-1,n});
        for(int i = n-1; i>=0; i--){
            if(arr[i] > st.top().first){
                right[i] = i;
                st.push({arr[i],i});
                continue;
            }
            while(arr[i]<=st.top().first)st.pop();
            right[i]=st.top().second-1;
            st.push({arr[i],i});
        }

        long long ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, (right[i]-left[i]+1)*arr[i]);
        }
        cout << ans<<"\n";

        cin>>n;
    }
}