#include<iostream>
#include<list>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n, k,tmp, yosepus=0;
    cin >> n >> k;
    list<int> human;
    int yo[n];

    for(int i = 1; i <= n; i++) human.push_back(i);

    auto it = human.begin();
    tmp=1;
    while(!human.empty()){
        if(it==human.end())it=human.begin();
        if(tmp==k){//k번째 사람까지 오면
            yo[yosepus++]= *it;
            auto now = it;
            it++;
            human.erase(now); //it = human.erase(it);으로 하면 축약 가능
            tmp=1;
        }
        else{//아직 k번째 사람이 아닐 경우
            tmp++;
            it++;
        }
    }

    cout<<"<";
    for(int i = 0; i < n-1; i++)cout << yo[i] << ", ";
    cout<<yo[n-1] << ">";
}