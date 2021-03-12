#include <bits/stdc++.h>
using namespace std;

//Counting the no of ways to arrange the buildings.
//o(n)
//Auxiliary space o(1)

int CountNoOfWays(int N)
{
    if (N == 1)
    {
        return 4;
    }

    int countB = 1;
    int countS = 1;
    int prev_countB;
    int prev_countS;

    for (int i = 2; i <= N; i++)
    {
        prev_countB = countB;
        prev_countS = countS;

        countS = prev_countB + prev_countS;
        countB = prev_countS;
    }

    int ans = countS + countB;

    return (ans * ans);
}

int main()
{
    int N = 3;
    cout << "No of possible ways to arrange the given building are:" << CountNoOfWays(N);
    return 0;
}