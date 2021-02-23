#include <bits/stdc++.h>
using namespace std;

//tamplete offring.
//o(n^2)
/*
int offeringNumbers(int n, int arr[])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int left = 0, right = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[j + 1])
            {
                ++left;
            }
            else
            {
                break;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                ++right;
            }
            else
            {
                break;
            }
        }
        sum += max(right, left) + 1;
    }

    return sum;
}

int main()
{
    int arr[] = {1, 2, 2};
    cout << offeringNumbers(3, arr);
    return 0;
}
*/

//efficent apporach using dp.
//o(n)

struct Lenght
{
    int L;
    int R;
};

int offeringNumbers(int arr[], int n)
{
    Lenght lenght_size[n];

    for (int i = 0; i < n; i++)
    {
        lenght_size[i].L = -1;
        lenght_size[i].R = -1;
    }

    lenght_size[0].L = 1;
    lenght_size[n - 1].R = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] < arr[i])
        {
            lenght_size[i].L = lenght_size[i - 1].L + 1;
        }
        else
        {
            lenght_size[i].L = 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i + 1] < arr[i])
        {
            lenght_size[i].R = lenght_size[i + 1].R + 1;
        }
        else
        {
            lenght_size[i].R = 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += max(lenght_size[i].L, lenght_size[i].R);
    }
    return sum;
}