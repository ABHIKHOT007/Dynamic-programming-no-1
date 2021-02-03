#include <bits/stdc++.h>
using namespace std;

//Ugly nubers
/*
int maxDivide(int a, int b)
{
    while (a % b == 0)
    {
        a = a / b;
    }
    return a;
}

int isUgly(int no)
{
    no = maxDivide(no, 2);
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);
}

int getnthUgly(int n)
{
    int i = 1;
    int count = 1;

    while (n > count)
    {
        i++;
        if (isUgly(i))
        {
            count++;
        }
    }
    return i;
}

int main()
{
    unsigned no=getnthUgly(150);
    cout << "nth ugly number is:"<<no<<"\n";
    return 0;
}*/

unsigned getnthUgelyno(unsigned n)
{
    unsigned ugly[n];
    unsigned i2 = 0;
    unsigned i3 = 0;
    unsigned i5 = 0;
    unsigned next_ugly_no = 1;
    unsigned next_multiple_of_2 = 3;
    unsigned next_multiple_of_3 = 2;
    unsigned next_mutliple_of_5 = 5;

    ugly[0] = 1;
    for (int i = 1; i < n; i++)
    {
        next_ugly_no = min(next_multiple_of_2, min(next_multiple_of_3, next_mutliple_of_5));
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2)
        {
            i2 = i2 + 1;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if (next_ugly_no == next_multiple_of_3)
        {
            i3 = i3 + 1;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if (next_ugly_no == next_mutliple_of_5)
        {
            i5 = i5 + 1;
            next_mutliple_of_5 = ugly[i5] * 5;
        }
    }
    return next_ugly_no;
}

int main()
{
    int n = 150;
    cout << getnthUgelyno(n);
    return 0;
}