#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int distance(string a, string b){
    int result = 0;
    for(int i = 0; i < 4; i++){
        if(a[i] != b[i]){
            result++;
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, dist, temp;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;
        if(n > 32){
            string ts;
            for(int x = 0; x < n; x++){
                cin >> ts;
            }
            cout << 0 << "\n";
            continue;
        }
        dist = 1000000;//이번 테스트케이스에서의 심리거리 최솟값 초기화
        vector<string> s(n);

        for(int j = 0; j < n; j++){
            cin >> s[j];
        }

        for(int j = 0; j < n-2; j++){
            for(int k = j+1; k < n-1; k++){
                for(int l = k+1; l < n; l++){
                    temp = distance(s[j], s[k]) + distance(s[k], s[l]) + distance(s[j], s[l]);
                    if(temp < dist){
                        dist = temp;
                    }
                }
            }
        }
        cout << dist << "\n";
    }
    
}