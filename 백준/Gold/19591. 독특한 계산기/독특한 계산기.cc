#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin>>s;
    deque<long long>num;
    deque<char>op;
    bool minus = s[0]=='-';
    long long tmp = minus?0:s[0]-'0';
    for(long long i = 1; i< s.size(); i++){
        if(s[i]>='0'&&s[i]<='9'){
            tmp*=10;
            tmp+= s[i]-'0';
        }
        else{
            if(minus){
                tmp*=-1;
                minus=0;
            }
            num.push_back(tmp);
            tmp=0;
            op.push_back(s[i]);
        }
    }
    if(minus)tmp*=-1;
    num.push_back(tmp);

    while(op.size()){
        char f = op.front(), b = op.back();
        long long first=0,second=0,last=num.size()-1;
        if(f=='+')first = num[0]+num[1];
        else if(f=='-')first = num[0]-num[1];
        else if(f=='*')first = num[0]*num[1];
        else first = num[0]/num[1];

        if(b=='+')second = num[last-1]+num[last];
        else if(b=='-')second = num[last-1]-num[last];
        else if(b=='*')second = num[last-1]*num[last];
        else second = num[last-1]/num[last];

        int res=0;
        if((f=='+' || f=='-') && (b=='*' || b=='/'))res=2;
        else if((b=='+' || b=='-') && (f=='*' || f=='/'))res=1;
        else if(first >= second)res=1;
        else res = 2;

        if(res==1){
            op.pop_front();
            num.pop_front();
            num.pop_front();
            num.push_front(first);
        }
        else{
            op.pop_back();
            num.pop_back();
            num.pop_back();
            num.push_back(second);
        }
    }
    cout<<num.front();
}