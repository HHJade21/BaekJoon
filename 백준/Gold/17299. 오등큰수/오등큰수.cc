#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,cnt[1000001]={0,};
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    vector<int>arr(n);//수열 저장할 배열
    vector<int>ans(n);//NGF배열
    stack<pair<int,int>>st;//빈도수, 인덱스 순서로 저장할 단조감소스택
    for(int i = 0;i < n;i++){
        cin>>arr[i];
        cnt[arr[i]]++;
    }

    st.push({cnt[arr[n-1]],n-1});//가장 오른쪽 숫자의 정보는 따로 초기화
    ans[n-1]=-1;

    for(int i = n-2; i>=0; i--){
        while(st.size() && cnt[arr[i]]>=st.top().first)st.pop();
        if(st.empty())ans[i] = -1;
        else ans[i] = arr[st.top().second];
        st.push({cnt[arr[i]],i});
    }
    for(int i = 0; i < n; i++)cout<<ans[i]<<" ";
    
}