#include <bits/stdc++.h>
using namespace std;

vector<int> findLIS(vector<int> arr, int n)
{
    vector<vector<int>> L(n);

    L[0].push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && (L[i].size() < L[j].size()))
            {
                L[i] = L[j];
            }
        }
        L[i].push_back(arr[i]);
    }

    int maxSize = 1;
    vector<int> lis;
    for (vector<int> x : L)
    {
        if (x.size() > maxSize)
        {
            lis = x;
            maxSize = x.size();
        }
    }
    return lis;
}

void minize(int input[], int n)
{
    vector<int> arr(input, input + n);
    while (arr.size())
    {
        vector<int> lis = findLIS(arr, arr.size());
        if (lis.size() < 2)
        {
            break;
        }
        for (int i = 0; i < arr.size() && lis.size() > 0; i++)
        {
            i--;
            lis.erase(lis.begin());
        }
    }
    int i;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    if (i == 0)
    {
        cout << "-1";
    }
}

int main()
{
    int input[] = {3, 2, 6, 4, 5, 1};
    int n = sizeof(input) / sizeof(input[0]);
    minize(input, n);
    return 0;
}