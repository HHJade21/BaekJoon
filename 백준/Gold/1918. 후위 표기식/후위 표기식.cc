#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    bool print = false;
    cin >> s;
    stack<char>st;
    for (int i = 0; i < s.size(); i++){
        if(s[i]>='A'&&s[i]<='Z'){
            cout<<s[i];
        }
        else if(s[i]=='+'||s[i]=='-'){//더하기빼기
            while(st.size() && st.top()!='('){
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i]=='*'||s[i]=='/'){//곱하기나누기
            if(st.size() && (st.top()=='*' || st.top()=='/')){
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i]=='('){//여는괄호
            st.push(s[i]);
        }
        else{//닫는괄호
            while(st.size() && st.top()!='('){
                cout << st.top();
                st.pop();
            }
            st.pop();
        }   
    }
    while(st.size()){
        if(st.top()!='(')cout<< st.top();
        st.pop();
    }
}