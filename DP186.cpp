#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[100];
    int n;
    int k,ans=0;
    cin>>n>>k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            if (arr[i] >= arr[k])
            {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}

