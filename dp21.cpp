#include <bits/stdc++.h>
using namespace std;
#define num_line 2
#define num_station 4

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int assembly(int a[][num_station], int t[][num_station], int *e, int *x)
{
    int t1[num_station];
    int t2[num_station];
    int i;

    t1[0] = e[0] + a[0][0];
    t2[0] = e[0] + a[1][0];

    for (int i = 1; i < num_station; i++)
    {
        t1[i] = min(t1[i - 1] + a[0][i], t2[i - 1] + t[1][i] + a[0][i]);
        t2[i] = min(t1[i - 1] + a[1][i], t1[i - 1] + t[0][i] + a[1][i]);
    }
    return min(t1[num_station - 1] + x[0], t2[num_station - 1] + x[1]);
}

int main()
{
    int a[][num_station] = {{4, 5, 3, 2}, {2, 10, 1, 4}};
    int t[][num_station] = {{0, 7, 4, 5}, {0, 9, 2, 8}};

    int e[] = {10, 12};
    int x[] = {18, 7};
    cout << assembly(a, t, e, x);
    return 0;
}