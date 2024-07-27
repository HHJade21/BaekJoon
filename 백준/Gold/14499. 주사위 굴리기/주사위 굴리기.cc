#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,m,o,y,x,cmd;
vector<vector<int>>map;
int dice[6]={0,}, tmp[6]={0,};

void moveUp(){//cmd==3
    if(y==0)return;

    y--;
    tmp[1]=dice[0];
    tmp[5]=dice[1];
    tmp[0]=dice[4];
    tmp[4]=dice[5];
    tmp[2]=dice[2];
    tmp[3]=dice[3];

    swap(tmp,dice);

    if(map[y][x]==0){
        map[y][x]=dice[5];
    }
    else{
        dice[5]=map[y][x];
        map[y][x]=0;
    }
    cout<<dice[0]<<"\n";
    return;
}

void moveDown(){//cmd==4
    if(y+1==n)return;

    y++;
    tmp[0]=dice[1];
    tmp[1]=dice[5];
    tmp[4]=dice[0];
    tmp[5]=dice[4];
    tmp[2]=dice[2];
    tmp[3]=dice[3];

    swap(tmp,dice);
    
    if(map[y][x]==0){
        map[y][x]=dice[5];
    }
    else{
        dice[5]=map[y][x];
        map[y][x]=0;
    }
    cout<<dice[0]<<"\n";
    return;
}

void moveLeft(){//cmd==2
    if(x==0)return;

    x--;
    tmp[3]=dice[0];
    tmp[0]=dice[2];
    tmp[2]=dice[5];
    tmp[5]=dice[3];
    tmp[1]=dice[1];
    tmp[4]=dice[4];

    swap(tmp,dice);
    
    if(map[y][x]==0){
        map[y][x]=dice[5];
    }
    else{
        dice[5]=map[y][x];
        map[y][x]=0;
    }
    cout<<dice[0]<<"\n";
    return;
}

void moveRight(){//cmd==1
    if(x+1==m)return;

    x++;

    tmp[0]=dice[3];
    tmp[2]=dice[0];
    tmp[5]=dice[2];
    tmp[3]=dice[5];
    tmp[1]=dice[1];
    tmp[4]=dice[4];

    swap(tmp,dice);
    
    if(map[y][x]==0){
        map[y][x]=dice[5];
    }
    else{
        dice[5]=map[y][x];
        map[y][x]=0;
    }
    cout<<dice[0]<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>y>>x>>o;
    map = vector<vector<int>>(n,vector<int>(m,0));

    for(int i = 0; i < n;i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < o; i++){
        cin>>cmd;
        //test
        // for(int i = 0; i < 6; i++){
        //     cout << dice[i] << " ";
        // }
        // cout<<" to ";


        if(cmd==1){//동
            moveRight();
        }
        else if(cmd==2){//서
            moveLeft();
        }
        else if(cmd==3){//북
            moveUp();
        }
        else{//남
            moveDown();
        }

        // for(int i = 0; i < 6; i++){
        //     cout << dice[i] << " ";
        // }
        // cout<<"\n";
    }


    // cout<<"\n";
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << map[i][j];
    //     }
    //     cout<<"\n";
    // }
}