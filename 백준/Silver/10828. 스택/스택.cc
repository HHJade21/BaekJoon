#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    stack<int>st;
    int n,a;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        if(s == "push"){
            cin>>a;
            st.push(a);
        }
        else if(s=="pop"){
            if(st.empty()) cout << -1 << "\n";
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if(s=="size"){
            cout << st.size() << "\n";
        }
        else if(s=="empty"){
            cout << st.empty() << "\n";
        }
        else{//top인 경우
            if(st.empty())cout << -1 << "\n";
            else cout << st.top() << "\n";
        }
    }
}