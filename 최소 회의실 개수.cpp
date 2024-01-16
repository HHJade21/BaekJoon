#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int>> open;
    priority_queue<int, vector<int>, greater<int>> exit;
    int max = 0, temp = 0, n, t1, t2;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t1 >> t2;
        open.push(t1);
        exit.push(t2);
    }

    while(!open.empty() && !exit.empty()){
        if(open.top() == exit.top()){
            if(temp == 0){
                if(temp+1>max){
                    max = temp;
                }
            }
            open.pop();
            exit.pop();

        }
        else if(open.top() < exit.top()){
            temp++;
            if(temp>max){
                max = temp;
            }
            open.pop();
        }
        else{
            exit.pop();
            temp--;
        }

    }

    cout << max;

}