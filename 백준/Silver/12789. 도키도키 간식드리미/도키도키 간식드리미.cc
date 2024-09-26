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
        if (line == num)
        {
            //test
            //cout << "line == num :" << line << "\n";
            
            num++;
        }
        else
        {
            //test
            //cout << "push " << line << "\n";

            wait.push(line);
        }

        while (wait.size() > 0 && wait.top() == num)
        {
            //test
            //cout << "pop" << wait.top() << ", num : " << num << "\n";

            wait.pop();
            num++;
            if(num>n){
                break;
            }
        }    
    }
    // 결과 출력
    if (wait.size() == 0)
    {
        cout << "Nice";
    }
    else
    {
        cout << "Sad";
    }
}