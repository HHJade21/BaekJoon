#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n=1,a,k=0;
    cin>>a;

    while(n<a){
        k++;
        n+=k*6;
    }
    cout<<k+1;

}