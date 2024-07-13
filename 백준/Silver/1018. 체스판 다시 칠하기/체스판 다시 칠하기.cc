#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int m, n, min = 100000000, bwcount, wbcount;

    cin >> m >> n;

    vector<vector<int>> map(m, vector<int>(n,0));
    vector<vector<int>> bw(m, vector<int>(n,0));
    vector<vector<int>> wb(m, vector<int>(n,0));

    //map 채우기
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j]=='B')map[i][j]=1;
            else map[i][j]=0;
        }
    }

    //bw, wb 채우기
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i%2==0){
                if(j%2==1){
                    bw[i][j]=0;
                    wb[i][j]=1;
                }
                else{
                    bw[i][j]=1;
                    wb[i][j]=0;
                }
            }
            else{
                if(j%2==0){
                    bw[i][j]=0;
                    wb[i][j]=1;
                }
                else{
                    bw[i][j]=1;
                    wb[i][j]=0;
                }
            }
        }
    }


    for(int i = 0; i <= m-8; i++){
        for(int j = 0; j <=n-8; j++){
            //잘랐으면 여기서 2중for문 돌면서 칠해야 될 사각형의 개수 count
            bwcount=0;
            wbcount=0;
            for(int p = i; p<i+8; p++){
                for(int q = j; q<j+8; q++){
                    if(map[p][q] != bw[p][q]) bwcount++;
                    else if(map[p][q]!=wb[p][q]) wbcount++;
                }
            }
            //현재 8*8격자에서 새로 칠해야 될 칸의 개수 모두 구한 상태.
            //min이랑 비교해서 갱신
            //min = 8, 
            //bwcount = 6
            //wbcount = 4
            if(min>bwcount)min=bwcount;
            if(min>wbcount)min=wbcount;
        }
    }

    cout<<min;
}