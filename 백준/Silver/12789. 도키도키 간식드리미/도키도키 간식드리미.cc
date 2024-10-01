#include <iostream>
#include <stack>
using namespace std;

int main()
{

    int n;
    int line, num = 1;
    cin >> n;

    stack<int> wait;

    for (int i=0; i<n; i++)
    {
        cin >> line;
        if (line == num) num++;
        else wait.push(line);

        while (wait.size() > 0 && wait.top() == num)
        {
            wait.pop();
            num++;
            
            if(num>n) break;
        }    
    }

    if (wait.size() == 0) cout << "Nice";
    else cout << "Sad";

}