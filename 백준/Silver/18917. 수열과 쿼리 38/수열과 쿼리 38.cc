#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    multiset<int> arr;
    int m, comm, value, ans4=0;
    long long sum=0;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> comm;
        if(comm==1){
            cin >> value;
            sum += value;
            ans4 ^= value;
            arr.insert(value);
        }
        else if(comm == 2){
            cin >> value;
            arr.erase(value);
            sum -= value;
            ans4 ^= value;
        }
        else if(comm == 3){
            cout << sum << "\n";
        }
        else{
            cout << ans4 << "\n";
        }
    }

}