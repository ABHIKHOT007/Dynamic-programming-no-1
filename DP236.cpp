#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    int n, x;
    cin >> n >> x >> str;
    for (int j = 0; j < x; j++){
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'B' && str[i + 1] == 'G')
            {
                str[i] = 'G';
                str[i + 1] = 'B';
                i++;
            }
        }
    }
    cout << str << endl;
    return 0;
}
