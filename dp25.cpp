#include <bits/stdc++.h>
using namespace std;

//printting the set partition.
//o(n*sum/2);

void printPartition(int arr[], int n)
{
    int i, j;
    int sum = accumulate(arr, arr + n, 0);
    if (sum & 1)
    {
        cout << "-1";
        return;
    }
    int k = sum >> 1;
    bool dp[n + 1][k + 1];
    //first row all values are zero because no of elements are zero then sum can't be formed.
    for (int i = 0; i <= k; i++)
    {
        dp[0][i] = false;
    }
    //first column all values are zero because sum zero can be formed from any elements.
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    //dp table bottom up manner.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            //excluding the element.
            dp[i][j] = dp[i - 1][j];
            //including the element.
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i][j] | dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    vector<int> set1, set2;
    if (!dp[n][k])
    {
        cout << "-1\n";
        return;
    }
    i = n;
    j = k;
    while (i > 0 && j >= 0)
    {
        //current element does not contribute to sum.
        //push into set2.
        if (dp[i - 1][j])
        {
            i--;
            set2.push_back(arr[i]);
        }
        else if (dp[i - 1][j - arr[i - 1]])
        {
            i--;
            j -= arr[i];
            set1.push_back(arr[i]);
        }
    }
    cout << "Set 1 elements:";
    for (int i = 0; i < set1.size(); i++)
    {
        cout << set1[i] << " ";
    }
    cout << "\n";
    cout << "set 2 elements:";
    for (int i = 0; i < set2.size(); i++)
    {
        cout << set2[i] << " ";
    }
}

int main()
{
    int arr[] = {5, 5, 1, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    printPartition(arr, n);
    return 0;
}