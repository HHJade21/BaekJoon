#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct info{
    int age;
    int order;
    string name;
};

bool cmp(info a, info b){
    if(a.age==b.age) return a.order<b.order;
    return a.age<b.age;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    vector<info> v;
    int n,a;
    string s;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a>>s;
        v.push_back({a,i,s});
    }
    sort(v.begin(),v.end(),cmp);

    for(int i = 0 ; i<n; i++){
        cout<<v[i].age << " " << v[i].name << "\n";
    }
}