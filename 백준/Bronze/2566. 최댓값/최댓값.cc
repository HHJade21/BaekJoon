#include<iostream> 
using namespace std;

int main(){
    int a[10][10],b,c,max=-1;

    for(int i = 1; i <=9;i++){
        for(int j = 1; j<=9; j++){
            cin>>a[i][j];
        }
    }

    for(int i = 1; i <=9;i++){
        for(int j = 1; j<=9; j++){
            cin>>a[i][j];
        }
    }

    for(int i = 1; i <=9;i++){
        for(int j = 1; j<=9; j++){
            if(a[i][j]>max){
                max=a[i][j];
                b=i;
                c=j;
            }
        }
    }
    cout<<max << "\n" << b << " " << c;
}