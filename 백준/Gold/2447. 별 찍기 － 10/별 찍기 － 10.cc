#include<iostream>
using namespace std;

bool r[2188][2188] = {0, };

void star(int size, int y, int x){
    if(size == 1){
        r[y][x] = true;
        return;
    }
    int s = size/3;
    for(int i = 0; i < size; i+=s){
        for(int j = 0; j < size; j+=s){
            if(i == s && j == s) continue;
            star(s, y+i, x+j);
        }
    }


}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    star(n, 1, 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(r[i][j]) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}