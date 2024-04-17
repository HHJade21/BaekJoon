#include<iostream>
#include<stack>
using namespace std;

long long a[2][2] = {0, 1, 1, 1}, ans[2][2] = {0, 1, 1, 1}, temp[2][2];
stack<bool> two;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n;
    cin >> n;
    if(n <= 1){
        cout << n;
        return 0;
    }
    n++;
    while(n>1){
        two.push(n%2);
        n/=2;
    }

    while(!two.empty()){
        temp[0][0] = (ans[0][0]*ans[0][0] + ans[0][1]*ans[1][0])%1000000007;
        temp[0][1] = (ans[0][0]*ans[0][1] + ans[0][1]*ans[1][1])%1000000007;
        temp[1][0] = (ans[0][0]*ans[1][0] + ans[1][0]*ans[1][1])%1000000007;
        temp[1][1] = (ans[1][0]*ans[0][1] + ans[1][1]*ans[1][1])%1000000007;
        swap(temp, ans);
        if(two.top()%2){
            temp[0][0] = (ans[0][0]*a[0][0] + ans[0][1]*a[1][0])%1000000007;
            temp[0][1] = (ans[0][0]*a[0][1] + ans[0][1]*a[1][1])%1000000007;
            temp[1][0] = (ans[1][0]*a[0][0] + ans[1][1]*a[1][0])%1000000007;
            temp[1][1] = (ans[1][0]*a[0][1] + ans[1][1]*a[1][1])%1000000007;
            swap(temp, ans);
        }
        two.pop();
    }
    
    cout << ans[0][0];
}