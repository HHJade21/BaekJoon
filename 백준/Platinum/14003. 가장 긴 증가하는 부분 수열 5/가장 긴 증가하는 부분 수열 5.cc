#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

/*솔루션

길이는 LIS2,3처럼 구한다. 
이때, ans벡터를 이차원으로 만들어놓고, 갱신될 때마다 push_back으로 해당 행에 넣는다(value, index 페어로). 
LIS를 출력할 때는 while(ans[i].idx>ans[i+1].idx)pop 한 뒤 올바른 lis가 되면 그때 출력

*/
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,tmp;
    cin>>n;
    vector<int>LIS;
    vector<vector<pair<int,int>>>ans;
    cin>>tmp;
    LIS.push_back(tmp);
    ans.push_back({});
    ans[0].push_back({tmp, 0});
    for(int i = 1 ; i < n; i++){
        cin>>tmp;
        if(tmp>LIS.back()){
            LIS.push_back(tmp);
            ans.push_back({});
            ans[ans.size()-1].push_back({tmp, i});
        }
        else{
            int idx = lower_bound(LIS.begin(), LIS.end(), tmp) - LIS.begin();
            LIS[idx]=tmp;
            ans[idx].push_back({tmp, i});
        }
    }
    cout<<LIS.size()<<"\n";
    for(int i = ans.size()-2; i>=0; i--){
        while(ans[i].back().second > ans[i+1].back().second)ans[i].pop_back();
    }
    for(int i = 0 ; i < ans.size(); i++)cout<<ans[i].back().first << " ";
}