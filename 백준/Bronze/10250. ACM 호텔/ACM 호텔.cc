#include<iostream>
using namespace std;
int main(){
    //101-201-301-..H-1 -> 102-202-302-...-H02
    int t, h, w, n;
    cin>>t;
    while(t--){
        cin>>h>>w>>n;
        if(n%h){
            cout<<(n%h)*100+((n-1)/h+1) << "\n";
        }
        else{//맨 윗층
            cout<<h*100+((n-1)/h+1) << "\n";
        }
    }
} 