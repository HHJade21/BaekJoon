#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, cnt = 1, tmp;
    int nums[1001];
    stack<int> a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for(int i = 0; i < n; i++){
        if(nums[i] == cnt){
            cnt++;
        }
        else if(!a.empty() && a.top() == cnt){
            while(!a.empty()){
                if(a.top() == cnt){
                    a.pop();
                    cnt++;
                }
                else
                    break;
            }

            a.push(nums[i]);
        }
        else{
            a.push(nums[i]);
        }
    }

    while(!a.empty()){
        if(a.top() == cnt){
            a.pop();
            cnt++;
        }
        else
            break;
    }

    if(cnt == n+1)
        cout << "Nice";
    else
        cout << "Sad";
}