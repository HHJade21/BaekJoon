#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int>>mpq;//음수 저장
    priority_queue<int> pq;//양수 저장
    bool zero = false;
    int n=0,a=0,tmp=0;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin >>a;
        if(a>0)pq.push(a);
        else if(a==0)zero = true;
        else mpq.push(a);
    }

    int result = 0;

    while(pq.size()>1){//큰 것부터 두 개씩 빼서 그 곱을 result에 더한다.
        if(pq.top()==1)break;//pq에 남은 수들이 전부 1일 경우 탈출
        tmp=pq.top();
        pq.pop();
        if(pq.top()==1){//위에서 tmp에 저장한 수와 곱할 숫자가 1일 경우
            result+=tmp;//일단 결과값에 tmp를 더하고
            break;//pop하지 않고 탈출한다.
        }
        tmp*=pq.top();
        pq.pop();
        result += tmp; 
    }
    while(pq.size()){//마지막 남은 양수 혹은 남은 1들을 전부 더해준다.
        result+=pq.top();
        pq.pop();
    }

    while(mpq.size()>1){//마찬가지로 음수 pq에서도 작은애들부터 곱해서 result에 더해준다.
        tmp = mpq.top();
        mpq.pop();
        tmp *= mpq.top();
        mpq.pop();//절대값이 가장 큰 음수 두개씩 빼와서 곱하고
        result += tmp;//결과값에 합산
    }

    if(mpq.size() && !zero){//음수 하나가 남았는데 0이 없는 경우
        result+=mpq.top();
    }

    cout << result;
}