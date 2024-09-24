#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int low = 1, high = k;
    while(low<high){
        int mid = (low+high)/2, cnt = 0;
        for(int i = 1; i<=n; i++)cnt += min(n, mid/i);
        if(cnt < k)low = mid+1;
        else high = mid;
    }
    cout << high;
}