#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> tower(n);
    vector<int> ans(n,0);
    stack<int> st;
    cin>>tower[0];
    ans[0]=-1;
    st.push(0);

    for(int i = 1; i < n; i++){
        cin >> tower[i];
        
        if(tower[i-1] >= tower[i]){
            ans[i] = i-1;
            st.push(i);
        }
        else{
            while(st.size()>0 && tower[st.top()] < tower[i]) st.pop();

            if(st.size()>0) ans[i] = st.top();
            else ans[i] = -1;

            st.push(i);
        }
    }

    for(int i = 0; i < n; i++){
        cout << ans[i]+1 << " ";
    }
}