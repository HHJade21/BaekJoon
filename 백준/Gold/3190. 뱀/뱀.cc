#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

queue<int> bodyY;//뱀의 몸이 위치해있는 칸들의 y좌표를 저장할 큐
queue<int> bodyX;//뱀의 몸이 위치해있는 칸들의 x좌표를 저장할 큐
int dir=0; //뱀의 머리가 보고 있는 방향을 나타내는 변수. 우하좌상
int headY=1, headX=1;//뱀의 머리 위치 저장 변수들
int dy[4]={0,1,0,-1}, dx[4]={1,0,-1,0};//0123에 우하좌상 방향 할당

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n, k, ty, tx, l, tmp, time=0;
    char c;

    cin >> n >> k;

    int map[101][101]={0,};//아무것도 없으면 0, 사과가 있으면 1, 뱀이 있으면 2

    for(int i = 0; i < k; i++){
        cin >> ty >> tx;//사과 위치 입력받고
        map[ty][tx]=1;//맵에 배치
    }

    //뱀 위치 초기 설정
    bodyY.push(1);
    bodyX.push(1);
    map[1][1]=2;//머리 배치

    cin >> l;//방향 전환 횟수
    queue<int>turnTime;//방향전환할 시간
    queue<char>turnDir;//전환할 방향
    for(int i = 0; i < l; i++){//방향 전환 정보 입력
        cin >> tmp >> c;
        turnTime.push(tmp);
        turnDir.push(c);
    }

    while(1){//게임 진행
        int ny = headY + dy[dir];//다음 이동할 위치의 y좌표
        int nx = headX + dx[dir];//다음 이동할 위치의 x좌표
        time++;
        if(ny<1||nx<1||ny>n||nx>n)//벽에 부딪히는 경우
            break;//게임 종료
        else if(map[ny][nx]==2)//자기 몸과 부딪히는 경우
            break;//게임 종료
        else if(map[ny][nx]==0){//그냥 빈칸일 경우
            //머리 이동
            headY = ny;//일단 head좌표 이동해주고
            headX = nx;
            bodyY.push(ny);//큐에 넣어주기
            bodyX.push(nx);
            map[ny][nx]=2;//맵에도 표시
            //머리가 한 칸 이동했으니 꼬리 끝쪽 삭제
            map[bodyY.front()][bodyX.front()]=0;//맵에서 지워주고
            bodyY.pop();//큐에서도 삭제
            bodyX.pop();
        }
        else{//사과가 있는 경우
            //머리 이동
            headY = ny;//일단 head좌표 이동해주고
            headX = nx;
            bodyY.push(ny);//큐에 넣어주기
            bodyX.push(nx);
            map[ny][nx]=2;//맵에도 표시
            //사과를 먹었으므로 꼬리는 움직이지 않는다.
        }

        if(time == turnTime.front()){//다음 방향 전환 시간일 경우
            if(turnDir.front()=='L'){//좌회전
                dir = (dir + 3)%4;
            }
            else{//우회전
                dir = (dir + 1)%4;
            }
            turnTime.pop();
            turnDir.pop();
        }
    }

    cout << time;
}