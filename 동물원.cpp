#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int a = 1, b = 1, c = 1, x, y, z, n;
    cin >> n;

    for(int i = 1; i < n; i++){
        x = (a+b+c)%9901;
        y = (a+c)%9901;
        z = (a+b)%9901;
        a = x;
        b = y;
        c = z;
    }
    cout << (a + b + c)%9901;
}