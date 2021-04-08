#include <bits/stdc++.h>
using namespace std;

//smallest number divisible by the first n numbers
//it just calculating the lcm of the given numbers from the 1 to n
//recursive apporach
//this is the property of the mulitplication of the gcd and lcm
//a*b=gcd(a,b)*lcm(a,b);
//converted formula is, lcm(a,b)=(a*b)/(gcd(a,b));

long long LCM(long long n)
{
    long long ans = 1;
    for (long long i = 1; i <= n; i++)
    {
        ans = (ans * i) / (__gcd(ans, i));
    }
    return ans;
}

int main()
{
    long long n = 20;
    cout << LCM(n);
    return 0;
}
