#include<iostream>
#include<vector>
using namespace std;
vector<int> arr(10000001, 0);
int pm[2] = {1, -1};
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int s, t;
    long long sum = 0;
    cin >> s >> t;
    for(int i = 1; i <= 10000000; i++){
        if(t/i==0){
            break;
        }
        else{
            if(s%i==0)
                sum += pm[i%2];
            sum += (t/i - s/i)*pm[i%2];
        }
    }
    cout << sum;
}