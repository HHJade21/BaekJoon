#include<iostream>
int main(){
    std::string s,res="";
    std::cin>>s;
    for(auto c : s){
        if (res.size() && res[0] >= c)res = c+res;
        else res+=c;
    }
    std::cout<<res;
}