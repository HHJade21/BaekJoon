#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,t=1;
    string name[20];
    char tmp;
    cin>>n;
    while(n){
        int m[20][20]={0,}, nCnt=0;
        cout<<"Group " << t++ << "\n";
        for(int i = 0 ; i < n; i++){
            cin>>name[i];
            for(int j = 0; j < n-1; j++){
                cin>>tmp;
                if(tmp=='N'){
                    m[i][j]=1;
                    nCnt++;
                }
            }
        }

        if(nCnt==0)cout<<"Nobody was nasty\n";
        else{
            for(int i = 0; i < n;i++){
                for(int j = 0; j < n-1;j++){
                    if(m[i][j]==1){
                        cout << name[(i - j - 1 + n)%n] << " was nasty about " << name[i] << "\n";
                    }
                }
            }
        }
        

        cin>>n;
        cout<<"\n";
    }
}
