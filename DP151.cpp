#include <bits/stdc++.h>
using namespace std;

//maximum no of traling zero's in the factorial of the given number.
//O(N)
//Traling zero's are the zeor's that appear's end of the number.
//traling zero's are equal to the no of count of five and two int the given number,
//if there are the more no five than the no of two then the total no traling zeor's are the,
//substraction of the count of five and count of two.

int findTrailingZeros(int n)
{
    int ans = 0;
    int p = 5;
    while ((n / p) > 0)
    {
        ans += (n / p);
        p = p * 5;
    }
    return ans;
}

int main()
{
    long long int n = 5;
    cout << findTrailingZeros(n);
    return 0;
}