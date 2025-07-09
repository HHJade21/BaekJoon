#include<iostream> 
using namespace std;
//11723 집합
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int s = 0, x,m;
    string c;

    cin>>m;
    for(int i = 0 ; i < m; i++){
        cin>>c;//명령어 입력
        if(c=="add"){
            cin>>x;
            s |= 1<<x;//or연산으로 s에 x를 더한다
        }
        else if(c=="remove"){
            cin>>x;
            //x번 비트 빼고 전부 1로 바꾼 뒤,이를 s와 and연산하여 s에서 x를 뺀다.
            s &= ~(1<<x);
        }
        else if(c=="check"){
            cin>>x;
            if(s&(1<<x))cout<<"1\n";//s의 x번째 비트가 1인지 확인
            else cout<<"0\n";
        }
        else if(c=="toggle"){
            cin>>x;
            s ^= (1<<x);//x번째 비트와 1을 xor연산하여 1이면 0으로, 0이면 1로 변경
        }
        else if(c=="all"){
            s=0;//모든 비트를 0으로 만든 뒤
            s = ~s;//전부 반전시켜 모든 비트를 1로 만든다.
        }
        else{//empty인 경우
            s = 0;//모든 비트를 0으로 만들어 비우기
        }
    }
}