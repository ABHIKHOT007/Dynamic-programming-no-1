#include <bits/stdc++.h>
using namespace std;

//Elephant question to reach the destination with minimum moves
/*
int main()
{
    int n;
    cin>>n;

    cout<<(n+4)/5<<"\n";

    return 0;
}*/

//pairwise maximum elements

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> a(3);
        for (auto &it : a)
            cin >> it;
        sort(a.begin(), a.end());
        if (a[1] != a[2])
        {
            cout << "NO"
                 << "\n";
        }
        else
        {
            cout << "YES"
                 << "\n"
                 << a[0] << " " << a[0] << " " << a[2] << "\n";
        }
    }

    return 0;
}
