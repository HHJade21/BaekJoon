#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n, m,tmp,h,c, ans = 999999;
struct p{
    int y;
    int x;
};

vector<p> house;
vector<p> chick;

vector<vector<int>> chickDist;

vector<bool> exs;

void findChickDist(int chickNum, int depth){
    if(depth == m){//m개의 치킨집이 모두 선정되었으면 치킨거리의 합과 ans를 비교하여 갱신
        //test
        //cout << "depth is " << m << ". chicken :";
        //for(int i = 0; i < c; i++){
            //if (exs[i])cout<<i << " ";
        //}cout<<"\n";

        int sum = 0;
        
        for(int i = 0 ; i < h; i++){//모든 집에서
            //가장 가까운 치킨거리 찾아서 sum에 합산
            int shortest = -1;
            for(int j = 0; j < c; j++){
                if(!exs[j])continue;

                if(shortest == -1){
                    shortest=j;
                }
                else if(chickDist[i][j]<chickDist[i][shortest])shortest=j;
            }
            sum += chickDist[i][shortest];
        }
        //test
        //cout << "sum : " << sum << "\n";
        ans = min(sum,ans);
    }
    else{//아니면 다음 depth로 재귀
        for(int i = chickNum+1; i < c; i++){
            exs[i]=true;
            findChickDist(i, depth+1);
            exs[i]=false;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;

    for(int i= 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tmp;
            if(tmp==1)house.push_back({i,j});
            else if(tmp==2)chick.push_back({i,j});
        }
    }
    h = house.size();
    c = chick.size();
    chickDist=vector<vector<int>>(h,vector<int>(c,0));
    exs = vector<bool>(c, false);

    //test code
    //cout << "chickDist:\n";

    for(int i = 0; i < h; i++){
        for(int j = 0; j <c; j++){
            chickDist[i][j]=abs(house[i].y-chick[j].y)+abs(house[i].x-chick[j].x);
            //test
            //cout << chickDist[i][j] << " ";
        }//cout<<"\n";
    }//이제 chickDist[i][j]에는 i번 집과 j번 치킨집 사이의 거리가 저장되어있음.

    //이제 치킨집 기준으로 조합 짜보기

    //test
    //cout << "h, c : " << h << ", " << c << "\n";

    for(int i = 0; i <= c-m; i++){
        exs[i]=true;
        findChickDist(i, 1);
        exs[i]=false;
    }

    cout << ans;
}