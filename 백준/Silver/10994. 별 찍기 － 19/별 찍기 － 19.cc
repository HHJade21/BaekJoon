#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n;
vector<vector<char>>map;

void star(int depth){
    for(int i = 0; i < (n-depth)*4-3; i++) map[depth*2][i+depth*2]='*';
    for(int i = 0; i < (n-depth)*4-3; i++) map[i+depth*2][depth*2]='*';
    for(int i = 0; i < (n-depth)*4-3; i++) map[(n*4-4)-depth*2][i+depth*2]='*';
    for(int i = 0; i < (n-depth)*4-3; i++) map[i+depth*2][(n*4-4)-depth*2]='*';
    if(depth<n-1) star(depth+1);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    map=vector<vector<char>>(n*4-3,vector<char>(n*4-3, ' '));

    star(0);

    for(int i = 0; i < n*4-3; i++){
        for(int j = 0; j < n*4-3; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}