#include<iostream>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    priority_queue<int>left;//왼쪽 숫자들
    priority_queue<int, vector<int>,greater<int>>right;
    int n,tmp;
    cin>>n;
    while(n--){
        cin>>tmp;
        if(left.size() == right.size()){//left에 넣어야 하는 경우
            if(right.empty() || right.top()>=tmp)left.push(tmp);
            else{
                right.push(tmp);
                left.push(right.top());
                right.pop();
            }
        }
        else {//right에 넣어야 하는 경우
            if(left.top()<=tmp)right.push(tmp);
            else{
                left.push(tmp);
                right.push(left.top());
                left.pop();
            }
        }
        cout<<left.top()<<"\n";
    }
}