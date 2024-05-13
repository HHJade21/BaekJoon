#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int cnt=0;
bool clear = false;

struct node{
    int y;
    int x;
    int s;
};

vector<vector<bool>>rExist(9,vector<bool>(10,0));
vector<vector<bool>>cExist(9,vector<bool>(10,0));
vector<vector<bool>>sExist(9,vector<bool>(10,0));

vector<vector<int>>map(9,vector<int>(9,0));

vector<node> zero;

void sol(int depth){
    int ny = zero[depth].y, nx = zero[depth].x, ns = zero[depth].s;
    //마지막 칸이면
    if(depth == cnt-1){
        for(int i = 1; i <= 9; i++){
            //찾으면 리턴
            if(!rExist[ny][i] && !cExist[nx][i] && !sExist[ns][i]){//찾으면
                rExist[ny][i] = true;
                cExist[nx][i] = true;
                sExist[ns][i] = true;
                map[ny][nx] = i;
                clear = true;
                return;
            }
        }
    }


    //마지막 빈칸 아니면 찾아보고 찾으면 재귀. 재귀 종료되면 방문 해제
    else{
        for(int i = 1; i <= 9; i++){
            if(clear) return;
            
            if(!rExist[ny][i] && !cExist[nx][i] && !sExist[ns][i]){//찾으면
                //방문표시하고 재귀한다.
                rExist[ny][i] = true;
                cExist[nx][i] = true;
                sExist[ns][i] = true;
                map[ny][nx] = i;

                sol(depth+1);

                if(clear)return;

                //재귀호출 종료되면 방문표시 해제.
                rExist[ny][i] = false;
                cExist[nx][i] = false;
                sExist[ns][i] = false;
                map[ny][nx] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    for(int i = 0; i < 9; i++){
        cin >> s;
        for(int j = 0; j < 9; j++) map[i][j] = s[j]-'0';
    }
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(map[i][j]>0){//숫자인경우
                rExist[i][map[i][j]]=true;
                cExist[j][map[i][j]]=true;
                sExist[(i/3)*3 + (j/3)][map[i][j]]=true;

            }

            else{//0인경우
                cnt++;
                zero.push_back({i,j,(i/3)*3 + (j/3)});
            }

        }
    }

    sol(0);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++) cout << map[i][j];

        cout << "\n";
    }
}