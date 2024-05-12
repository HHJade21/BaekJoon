#include<iostream>
using namespace std;
int main(){
    int n, a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(a<b) cout << "NO BRAINS\n";
        else cout << "MMM BRAINS\n";
    }
}