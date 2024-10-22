#include<iostream>
using namespace std;

int main(){
    int n=1,a,k=0;
    cin>>a;

    while(a<n||n+(k*6)<a){
        n+=(k*6);
        k++;
    }
    cout<<k+1;

}