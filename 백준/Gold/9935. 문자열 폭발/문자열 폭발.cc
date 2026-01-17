#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s,bomb;
    string st;//스택처럼 쓸 문자열(push하듯이 글자 하나씩 붙여넣기 할거임.)
    cin>>s>>bomb;
    for(auto c : s){
        st+=c;
        if(st.size() >= bomb.size() && c==bomb[bomb.size()-1]){
            bool isBomb = true;
            for(int i = 1; i<=bomb.size(); i++){
                if(st[st.size()-i] != bomb[bomb.size()-i]) isBomb = false;
            }
            if(isBomb) st.erase(st.begin()+st.size()-bomb.size(), st.end());
        }
    }
    if(st.size())cout<<st;
    else cout << "FRULA";
}