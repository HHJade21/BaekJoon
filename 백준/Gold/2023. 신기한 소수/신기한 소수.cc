#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<cmath>
using namespace std;
int n;

void amazing(string s){
    int tmp = stoi(s);
    for(int k = 2; k <= sqrt(tmp);k++){
        if(tmp%k==0){
            return;
        }
    }
    //s가 소수인 경우
    if(s.size()==n){
        cout << s << "\n";
    }
    else{
        amazing(s+"1");
        amazing(s+"3");
        amazing(s+"7");
        amazing(s+"9");
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;

    amazing("2");
    amazing("3");
    amazing("5");
    amazing("7");

}