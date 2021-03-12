#include <bits/stdc++.h>
using namespace std;

//calculating the sum of the four element which equls to the given sum.
//O(N^4)
/*
void FourEleSum(int arr[], int n, int sum)
{
    for (int i = 0; i <= n - 3; i++)
    {
        for (int j = i + 1; j <= n - 2; j++)
        {
            for (int k = j + 1; k <= n - 1; k++)
            {
                for (int l = k + 1; l <= n; l++)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == sum)
                    {
                        cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l] << "\n";
                    }
                }
            }
        }
    }
}
*/
//O(N^3)

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void FourEleSum(int arr[], int n, int sum)
{
    int start;
    int end;

    qsort(arr, n, sizeof(arr[0]), compare);

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            start = j + 1;
            end = n - 1;
            while (start < end)
            {
                if (arr[i] + arr[j] + arr[start] + arr[end] == sum)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[start] << " " << arr[end] << "\n";
                    start++;
                    end--;
                }
                else if (arr[i] + arr[j] + arr[start] + arr[end] < sum)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
    }
}


int main()
{
    int arr[] = {10, 20, 30, 40, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    FourEleSum(arr, n, 91);
    return 0;
}