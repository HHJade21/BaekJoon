#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    string s;
    cin >> t;
    for(int k = 0; k < t; k++){
        cin >> s;
        int size = s.length();
        if(size==1){
            cout << "0\n";
            continue;
        }
        else if(size==2){
            if(s[0]=s[1]){
                cout << "0\n";
                continue;
            }
            else{
                cout << "1\n";
                continue;
            }
        }

        int right = size-1;
        int pal = 0;
        for(int i = 0; i <= size/2;i++){
            
            if(s[i] != s[right]){
                int right2 = right-1;
                //둘 중 하나 지우고 마저 해본다.
                for(int j = i+1; j <= size/2; j++){//왼쪽거 지워보기
                    if(s[j]!=s[right]){
                        pal=2;
                        break;
                    }
                    right--;
                }
                if(pal==0){
                    pal = 1;
                    break;
                }
                pal = 0;
                for(int j = i; j <= size/2; j++){//오른쪽거 지워보기
                    if(s[j]!=s[right2]){
                        pal=2;
                        break;
                    }
                    right2--;
                }
                if(pal==0){
                    pal=1;
                    break;
                }
            }
            if(pal==1 || pal == 2)break;
            right--;
        }
        cout << pal << "\n";
    }
}