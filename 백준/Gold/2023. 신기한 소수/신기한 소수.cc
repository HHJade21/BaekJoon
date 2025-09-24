#include<iostream>
using namespace std;
int n;

void amazing(int now, int depth){
    for(int i = 2; i*i<=now; i++){
        if(now%i==0)return;
    }

    if(depth==n) cout << now << "\n";
    else{
        amazing(now*10+1, depth+1);
        amazing(now*10+3, depth+1);
        amazing(now*10+7, depth+1);
        amazing(now*10+9, depth+1);
    }
}
int main(){
    cin>>n;
    amazing(2,1);
    amazing(3,1);
    amazing(5,1);
    amazing(7,1);
}