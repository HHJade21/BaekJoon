#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    long long sum = 0;
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    vector<int> b(n, 0);
    stack<int> s;
    for(int i = 0; i < n; i++)
        cin >> b[i];
    s.push(n-1);
    for(int i = n-2; i >= 0; i--){
        while(!s.empty()){
            if(b[s.top()] >= b[i]){
                sum += s.top() - 1 - i;
                break;
            }
            s.pop();
        }
        if(s.empty())
            sum += n-1-i;
        s.push(i);
    }
    cout << sum;
}