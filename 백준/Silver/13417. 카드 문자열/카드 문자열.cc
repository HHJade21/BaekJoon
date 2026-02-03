#include<iostream>
#include<deque> 
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t,n;
    char c;
    cin>>t;
    while(t--){
        cin>>n;
        string s="";
        while(n--){
            cin>>c;
            if(s.size()==0 || s[0] < c)s+=c;
            else s = c+s;
        }
        cout<<s<<"\n";
    }
}