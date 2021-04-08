#include <bits/stdc++.h>
using namespace std;

//finding the LCM of the given two numbers
//recursive apporach
//15=5*3
//25=5*5
//union of all factors=5*5*3=75

long long GCD(long long int a, long long int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return GCD(b, a % b);
    }
}

long long lcm(int a, int b)
{
    return (a / GCD(a, b)) * b;
}

int main()
{
    int a = 15;
    int b = 20;
    cout << lcm(a, b);
    return 0;
}