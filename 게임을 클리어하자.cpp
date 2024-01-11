#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int b[500] = {0,}, a[500] = {0,}, n, m, min;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[j];
            min = 5000000;
            for(int k = 0; k < m; k++){
                if(j!=k && b[k] + a[j] < min){
                    min = b[k]+a[j];
                }
            }
            a[j] = min;
        }
        swap(a, b);
    }

    min = 5000000;
    for(int i = 0; i < m; i++){
        min = b[i]<min?b[i]:min;
    }
    cout << min;
}