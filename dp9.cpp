#include <bits/stdc++.h>
using namespace std;

//No of ways the tile can be placed in given 2n board size.
int NoOfWays(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return NoOfWays(n - 1) + NoOfWays(n - 2);
}

int main()
{
    cout << "NO of ways the tile can be placed is:" << NoOfWays(10) << endl;
    cout << "No of ways the tile can be placed is:" << NoOfWays(3) << endl;
    return 0;
}