#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, w, l, sum = 0, time = 0,tmp;
    cin >> n >> w >> l;
    stack<int> st;
    queue<int> q;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        st.push(tmp);
    }

    for(int i = 0; i <= n*w; i++){
        if(st.empty()&&sum==0)break;

        if(q.size() == w){
            sum -= q.front();
            q.pop();
        }

        if(!st.empty() && sum + st.top() <= l){
            sum += st.top();
            q.push(st.top());
            st.pop();
        }
        else{
            q.push(0);
        }

        time++;
    }

    cout << time;
}