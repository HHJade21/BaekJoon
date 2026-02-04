#include<iostream>
main(){std::string s,r;std::cin>>s;for(auto c:s)r=min(c+r,r+c);std::cout<<r;}