#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==0)cout<<c*c-b;
    else if(b==0)cout<<c*c-a;
    else cout<<sqrt(a+b);
}