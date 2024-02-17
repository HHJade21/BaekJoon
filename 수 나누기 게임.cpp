#include<iostream>
#include<vector>
using namespace std;
int n, size, score[1000001] = {0,}, tmp;
bool exist[1000001] = {0,};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        exist[a[i]] = 1;
    }

    for(int i = 0; i < n; i++){
        tmp = a[i];
        for(int j = tmp*2; j <=1000000; j+=tmp){
            if(exist[j]){
                score[tmp]++;
                score[j]--;
            }
        }
    }

    for(auto i : a){
        cout << score[i] << " ";
    }
    
}