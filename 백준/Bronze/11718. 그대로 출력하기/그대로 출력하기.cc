#include <iostream>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    
    while(s != ""){
        cout << s <<"\n";
        getline(cin, s);
    }
}
