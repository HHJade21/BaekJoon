#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    stack<char>qual;
    stack<int>score;
    int tmp=0,ans=0;

    string s;
    cin>> s;

    for(int i = 0; s[i]; i++){
        //test code
        //cout << "s[" << i << "] : " << s[i] << ", ";
        //if(qual.size())cout<<"qual.top : " << qual.top() << ", ";
        //if(score.size())cout << "score.top : " << score.top() << ", ";

        if(s[i]=='(' || s[i]=='['){//여는 괄호일 경우
            qual.push(s[i]);
            score.push(0);
        }
        else if(s[i]==')'){
            if(qual.empty() || qual.top() == '['){//올바르지 않은 괄호인 경우
                cout << 0;
                return 0;
            }
            //올바른 괄호쌍인 경우
            if(score.top()==0)tmp=2;//바깥쪽 괄호에 2더하기
            else tmp = score.top() * 2;//바깥쪽 괄호에 (괄호안내용물)*2더하기

            score.pop();//바깥에 더해줄 점수 tmp에 꺼내놨으니 score하나 pop
            qual.pop();//열려있던 괄호가 닫혀버렸으니 얘도 pop

            if(score.empty()){//바깥쪽 괄호가 더이상 없을 경우
                ans += tmp;//방금 닫힌 괄호열에서 꺼낸 값을 답에 더해준다.
            }
            else{//바깥쪽을 감싼 괄호가 남아있을 경우
                tmp = score.top() + tmp;//바깥쪽 점수에 tmp를 합산해 저장하고
                score.pop();
                score.push(tmp);//바깥쪽 점수를 걔로 바꿔준다.
            }
        }
        else{//닫는 대괄호인 경우
            if(qual.empty() || qual.top() == '('){//올바르지 않은 괄호열
                cout << 0;
                return 0;
            }

            //올바른 괄호열인 경우
            if(score.top()==0)tmp=3;//바깥쪽 괄호열에 3을 더해주기
            else tmp = score.top()*3;//[안쪽내용물]*3을 더해주기.

            score.pop();
            qual.pop();

            if(score.empty()){
                ans += tmp;
            }
            else{
                tmp = score.top() + tmp;
                score.pop();
                score.push(tmp);
            }
        }

        //test code
        //cout << "ans : " << ans << ", temp : " << tmp << "\n";
    }

    if(qual.size())cout << 0;
    else cout << ans;
}