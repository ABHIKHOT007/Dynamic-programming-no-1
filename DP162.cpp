#include <bits/stdc++.h>
using namespace std;

//minimum swaps required to sort the array.
//O(NlogN)

int minSwaps(int arr[], int n)
{
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    sort(arrPos, arrPos + n);
    vector<bool> vis(n, false);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == true || arrPos[i].second == i)
        {
            continue;
        }
        int no_of_swaps = 0;
        int j = i;
        while (vis[j] == false)
        {
            vis[j] = 1;
            j = arrPos[j].second;
            no_of_swaps++;
        }
        if (no_of_swaps > 0)
        {
            ans += (no_of_swaps - 1);
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 5, 4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minSwaps(arr, n);
    return 0;
}
