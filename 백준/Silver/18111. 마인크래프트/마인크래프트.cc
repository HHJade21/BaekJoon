#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n,m,b,ans_t=INT_MAX,ans_h=0;
    cin>>n>>m>>b;

    vector<vector<int>>ground(501,vector<int>(501,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>ground[i][j];
        }
    }
    for(int h=0; h<257; h++){
        int block=b, time=0;
        bool check=true;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(h<ground[i][j]){
                    block+=ground[i][j]-h;
                    time+=((ground[i][j]-h)*2);
                }
                else if(h>ground[i][j]){
                    block-=(h-ground[i][j]);
                    time+=(h-ground[i][j]); 
                }               
            }
        }
        if(block>=0){
            if(time<ans_t){
                ans_t=time;
                ans_h=h;
            }
            else if(time==ans_t){
                ans_h=max(ans_h,h);
            }
        }
    }
    cout<<ans_t<<" "<<ans_h;
}
