#include<iostream>
using namespace std;
string st, s;
int t,n;
bool bomb(){
    if(st.size()<3 || st[st.size()-1]!='B' || st[st.size()-2]!='B' || st[st.size()-3]!='A')return false;
    return true;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>s;
        st="";
        for(int i = 0; i < n;i++){
            st+=s[i];
            int cnt=0;
            while(bomb()){
                st.erase(st.end()-3, st.end());
                st += "B";
                cnt++;
            }
            for(int j = 0; j < cnt; j++)st+="A";
        }
        cout<<st<<"\n";
    }
}