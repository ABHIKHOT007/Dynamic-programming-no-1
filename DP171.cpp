#include <bits/stdc++.h>
using namespace std;

//min max sum of the subarray of the given k window
//O(n)

int minMax(int k, vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int ans = INT_MAX;
    for (int i = 0; i + k - 1 < n; i++)
    {
        ans = min(ans, arr[i + k - 1] + arr[i]);
    }
    
     return ans;
}

int main()
{
    cout << minMax(3, {10, 11, 300, 200, 1000, 20});
    return 0;
}