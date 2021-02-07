#include <bits/stdc++.h>
using namespace std;

int countsetbit(int n, int diff)
{
    if (abs(diff) > 2)
    {
        return 0;
    }

    if (n == 1 && diff == 0)
    {
        return 2;
    }
    if (n == 1 && abs(diff) == 1)
    {
        return 1;
    }

    int res = countsetbit(n - 1, diff) + 2 * countsetbit(n - 1, diff) + countsetbit(n - 1, diff - 1);

    return res;
}

int main()
{
    int n = 2;
    cout << "count of sequences is:" << countsetbit(2, 0);
    return 0;
}
