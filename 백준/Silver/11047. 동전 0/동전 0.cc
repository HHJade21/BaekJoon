#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,k,tmp,ans=0;
    cin>>n>>k;
    stack<int>coin;
    while(n--){//n개 동전 가격 입력
        cin>>tmp;
        coin.push(tmp);//스택에 넣기(뒤에서부터 볼거니까)
    }
    while(k){
        ans+=k/coin.top();
        k%=coin.top();
        coin.pop();
    }
    cout<<ans;
}