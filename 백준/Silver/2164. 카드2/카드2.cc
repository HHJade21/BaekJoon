#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    queue<int> q;//int형 큐 선언

    int n;
    cin >> n;

    //카드 뭉치의 맨 윗면을 front, 맨 아랫면을 back으로 설정.
    //삭제가 이루어지는 front에 1이, 삽입이 이루어지느 back에 n이 오도록 큐에 삽입.
    for(int i = 1; i <= n; i++)q.push(i);

    while(q.size()>1){
        //맨 위의 카드를 바닥에 버린다.
        q.pop();
        //맨 위의 카드를 맨 아래로 옮긴다.
        q.push(q.front());
        q.pop();
    }

    cout << q.front();
}