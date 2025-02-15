#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,a,b,st=-1000000000,ed=-1000000000,ans=0;
    cin>>n;
    for(int i = 0 ;i<n;i++){
        cin>>a>>b;
        if(ed<a){
            ans+=ed-st;
            st=a;
            ed=b;
        }
        else ed=max(ed,b);
    }
    ans+=ed-st;
    cout<<ans;
}