#include <bits/stdc++.h>
using namespace std;

struct area
{
    int a;
    int b;
    area(int a, int b)
    {
        a = a;
        b = b;
    }
};

int max(int a, int b, int c)
{
    return max(a, max(b, c));
}

int maxsurival(int A, int B, area X, area Y, area Z, int last, map<pair<int, int>, int> &memo)
{
    if (A <= 0 || B <= 0)
    {
        return 0;
    }
    pair<int, int> curr = make_pair(A, B);

    if (memo.find(curr) != memo.end())
    {
        return memo[curr];
    }

    int temp=0;

    switch (last)
    {
    case 1:
        temp = 1 + max(maxsurival(A + Y.a, B + Y.b, X, Y, Z, 2, memo), maxsurival(A + Z.a, B + Z.b, X, Y, Z, 3, memo));
        break;
    case 2:
        temp = 1 + max(maxsurival(A + X.a, B + X.b, X, Y, Z, 1, memo), maxsurival(A + Z.a, B + Z.b, X, Y, Z, 3, memo));
        break;
    case 3:
        temp = 1 + max(maxsurival(A + X.a, B + X.b, X, Y, Z, 1, memo), maxsurival(A + Y.a, B + Y.b, X, Y, Z, 2, memo));
        break;
    }

    memo[curr] = temp;
}

int getmaxsurivaltime(int A, int B, area X, area Y, area Z)
{
    if (A <= 0 || B <= 0)
    {
        return 0;
    }
    map<pair<int, int>, int> memo;
    return max(maxsurival(A + X.a, B + X.b, X, Y, Z, 1, memo),
               maxsurival(A + Y.a, B + Y.b, X, Y, Z, 2, memo),
               maxsurival(A + Z.a, B + Z.b, X, Y, Z, 3, memo));
}

int main()
{
    area X(3, 2);
    area Y(-5, -10);
    area Z(-20, 5);

    int A = 20;
    int B = 8;

    cout << "maximum surival time would be:" << getmaxsurivaltime(A, B, X, Y, Z) << "\n";
    return 0;
}