#include<iostream>
using namespace std;
int n;
void amazing(int now, int depth){
    for(int i = 2; i*i<=now; i++){
        if(now%i==0)return;
    }
    if(depth==n) cout << now << "\n";
    else{
        for(int i = 1; i<=9; i+=2)amazing(now*10+i, depth+1);
    }
}
int main(){
    cin>>n;
    for(int i = 2; i<=7; i++)amazing(i,1);
}