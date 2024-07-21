#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
typedef long long ll;

int n, ans = 0;

//상하좌우 이동 함수들
vector<vector<int>> MoveUp(vector<vector<int>> map){
    vector<vector<bool>>merged(n, vector<bool>(n,0));//합쳐진 블록 표시할 임시 배열
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //해당 칸에 있는 블록 위로 밀기
            if(map[i][j]==0)continue;//블럭 아니고 빈공간이면 패스하고
            int y = i;
            while(y>0 && map[y-1][j]==0){//블럭이면 계속 위로 올리기
                map[y-1][j]=map[y][j];
                map[y][j]=0;
                y--;
            }
            //만약 위에 합칠 수 있으면
            if(y>0 && map[y-1][j]==map[y][j] && !merged[y-1][j]){
                map[y-1][j]*=2;//합치고
                map[y][j]=0;
                merged[y-1][j]=true;//표시해두기
            }
        }
    }
    return map;
}

vector<vector<int>> MoveDown(vector<vector<int>> map){
    vector<vector<bool>>merged(n, vector<bool>(n,0));//합쳐진 블록 표시할 임시 배열
    for(int i = n-1; i >=0; i--){
        for(int j = 0; j < n; j++){
            //해당 칸에 있는 블록 아래로 밀기
            if(map[i][j]==0)continue;//블럭 아니고 빈공간이면 패스하고
            int y = i;
            while(y<n-1 && map[y+1][j]==0){//블럭이면 계속 아래로 내리기
                map[y+1][j]=map[y][j];
                map[y][j]=0;
                y++;
            }
            //만약 아래에 합칠 수 있으면
            if(y<n-1 && map[y+1][j]==map[y][j] && !merged[y+1][j]){
                map[y+1][j]*=2;//합치고
                map[y][j]=0;
                merged[y+1][j]=true;//표시해두기
            }
        }
    }
    return map;
}

vector<vector<int>> MoveLeft(vector<vector<int>> map){
    vector<vector<bool>>merged(n, vector<bool>(n,0));//합쳐진 블록 표시할 임시 배열
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //해당 칸에 있는 블록 왼쪽으로 밀기
            if(map[i][j]==0)continue;//블럭 아니고 빈공간이면 패스하고
            int x = j;
            while(x>0 && map[i][x-1]==0){//블럭이면 계속 왼쪽으로 밀기
                map[i][x-1]=map[i][x];
                map[i][x]=0;
                x--;
            }
            //만약 왼쪽에 합칠 수 있으면
            if(x>0 && map[i][x-1]==map[i][x] && !merged[i][x-1]){
                map[i][x-1]*=2;//합치고
                map[i][x]=0;
                merged[i][x-1]=true;//표시해두기
            }
        }
    }
    return map;
}


vector<vector<int>> MoveRight(vector<vector<int>> map){
    vector<vector<bool>>merged(n, vector<bool>(n,0));//합쳐진 블록 표시할 임시 배열
    for(int i = 0; i < n; i++){
        for(int j = n-1 ; j >=0 ; j--){
            //해당 칸에 있는 블록 오른쪽으로 밀기
            if(map[i][j]==0)continue;//블럭 아니고 빈공간이면 패스하고
            int x = j;
            while(x<n-1 && map[i][x+1]==0){//블럭이면 계속 오른쪽으로 밀기
                map[i][x+1]=map[i][x];
                map[i][x]=0;
                x++;
            }
            //만약 오른쪽에 합칠 수 있으면
            if(x<n-1 && map[i][x+1]==map[i][x] && !merged[i][x+1]){
                map[i][x+1]*=2;//합치고
                map[i][x]=0;
                merged[i][x+1]=true;//표시해두기
            }
        }
    }
    return map;
}

//최대값 찾아서 ans에 갱신해주기
void GetMaxBlock(vector<vector<int>> map){
    //test code
    //bool ex128=false;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ans < map[i][j])ans = map[i][j];


            //test code
            // if(map[i][j]==128){
            //     ex128 = true;
            // }
        }
    }

    // if(ex128){
    //     for(int i = 0; i < n; i++){
    //         for(int j = 0; j < n; j++){
    //             cout << map[i][j] << " ";
    //         }
    //         cout<<"\n";
    //     }
    //     cout<<"\n\n";
    // }
}



void DFS(vector<vector<int>>map, int depth){
    if(depth==5){
        GetMaxBlock(map);
        return;
    }
    else{
        DFS(MoveUp(map), depth+1);
        DFS(MoveDown(map), depth+1);
        DFS(MoveLeft(map), depth+1);
        DFS(MoveRight(map), depth+1);
        return;
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


    cin>>n;

    vector<vector<int>> map(n, vector<int>(n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    DFS(map, 0);

    cout << ans;
}