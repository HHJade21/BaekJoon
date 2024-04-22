#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t, one = 0, zero = 0,ing = 0, mode=0, success=1;
    string s;
    cin >> t;
    for(int k = 0; k < t; k++){
        cin >> s;
        for(int i=0; s[i]!='\0'; i++){
            if(mode==1){
                if(s[i]=='0'){
                    if(one==1){//11..0이 나온 경우 뒤에가 1인지 0인지에 따라 모드가 달라진다. 
                        mode=2;
                        continue;
                    }
                    else if(one>1){
                        if(s[i+1]=='0'){
                            zero=1;
                            one=0;
                            continue;
                        }
                        else {
                            mode=2;
                            continue;
                        }
                    }
                    zero++;
                }
                else{//s[i]=='1'case
                    if(zero<2){
                        success=0;
                        break;
                    }
                    one++;
                    continue;
                }
            }

            else if(mode==2){
                if(s[i]=='1'){
                    mode=0;
                    continue;
                }
                success = 0;
                break;
            }

            else if(s[i]=='1'){//a문장 시작
                mode=1;
                zero=0;
                one=0;
            }
            else{//b문장 시작
                mode=2;
            }
        }

        if(mode==1&&s.back()!='1'){//a문장이 종료되지 않았는지 확인
            success=0;
        }
        else if(mode==1 && zero==0){
            success=0;
        }
        else if(mode==2&&s.back() != '1'){
            success=0;
        }

        if(success)cout<<"YES\n";
        else cout << "NO\n";
        mode=0;
        zero=0;
        one=0;
        success=1;
    }
}