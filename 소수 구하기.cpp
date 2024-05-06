#include<iostream>
using namespace std;
bool prime[1000001]={0,};


int main(){
    int a, b;
    cin >> a >> b;
    prime[0]=1;
    prime[1]=1;

    for(int i = 2; i <= 1000; i++){
        if(prime[i]==0){
            for(int j = i*2; j<=1000000; j+=i){
                prime[j]=true;
            }
        }
    }

    for(int i = a; i <= b; i++){
        if(prime[i]==0) cout << i << "\n";
    }
}