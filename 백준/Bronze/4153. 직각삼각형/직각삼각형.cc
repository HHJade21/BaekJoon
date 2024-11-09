#include<iostream>
using namespace std;
int main(){
    int a, b, c;
    cin>>a>>b>>c;
    while(a!=0 || b!=0 || c!=0){
        if(b>=a&&b>=c)
            swap(a,b);
        else if(c>=a&&c>=b)
            swap(a,c);
        if(a*a == b*b+c*c)cout<<"right\n";
        else cout<<"wrong\n";
        cin>>a>>b>>c;
    }
}