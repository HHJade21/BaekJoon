#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, k;
    cin >> n >> k;//n은 초기 문자열의 길이, k는 지워야 하는 글자의 수
    string s;
    cin >> s;

    int idx = 0;

    stack<int>st;

    st.push(0);

    for(int i = 1; i < n; i++){
        if(st.size() && s[st.top()] < s[i]){//만약 top 인덱스의 숫자보다 i의 숫자가 크면
            s[st.top()]='!';//top 인덱스의 숫자를 지운다.
            st.pop();
            k--;//남은 지울 문자의 개수 1감소
            if(k==0)break;
            i--;
        }
        else{//top인덱스의 숫자보다 작은 숫자가 나오면
            st.push(i);
        }
    }

    while(k--){
        s[st.top()]='!';
        st.pop();
    }

    for(auto i : s){
        if(i!='!')cout<<i;
    }
}