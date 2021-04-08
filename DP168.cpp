#include <bits/stdc++.h>
using namespace std;

//k'th last person to surive in the game.
//position of the last surived pareson calculated by the taking the formula (x+k)%n this ensure that index can't go out bound.
///recursive apporach

int solve(int n, int k)
{
    if (n == 0)
    {
        return 0;
    }

    int x = solve(n - 1, k);
    int y = (x + k) % n;

    return y;
}

int main()
{
    int n = 5;
    int k = 3;
    cout << solve(n, k);
    return 0;
}
