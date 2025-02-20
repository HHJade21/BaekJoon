#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){//솔루션 : 뺄셈이 나오면 뒤쪽 항들을 묶어서 최대한 크게 뺀다.
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin>>s;
    int tmp=0,ans=0;
    bool minus=0;//지금 빼는중인지 아닌지
    for(auto i : s){//문자열의 앞에서부터 탐색
        if('0'<=i && i<='9'){//숫자가 나오면
            tmp = tmp*10 + int(i-'0');
            //test
            // cout << "num";
        }
        else if(i=='+'){//덧셈이면
            if(minus){
                ans -= tmp;
            }
            else{
                ans += tmp;
            }

            tmp=0;
            //test 
            // cout << "ans : " << ans << "\n";
        }
        else{//뺄셈이면
            if(minus)ans-=tmp;
            else ans+=tmp;

            minus=true;
            tmp=0;

            //test 
            // cout << "ans : " << ans << "\n";
        }
    }
    if(minus)ans-=tmp;
    else ans+=tmp;

    //test 
    // cout << "ans : " << ans << "\n";

    cout << ans;
}