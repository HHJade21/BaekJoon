#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int block[500], ans = 0;
    int w, h;
    cin >> h >> w;

    for (int i = 0; i < w; i++)
    {
        cin >> block[i];
    }

    for (int i = 0; i < w; i++)
    {
        int left = block[i], right = block[i];

        for (int j = i - 1; j >= 0; j--)
        { // left구하기
            if (block[j] > left)
                left = block[j];
        }

        for (int j = i + 1; j < w; j++)
        { // right구하기
            if (block[j] > right)
                right = block[j];
        }

        int result = min(left, right);
        if (result > block[i])
            ans += (result - block[i]);
    }

    cout << ans;
}