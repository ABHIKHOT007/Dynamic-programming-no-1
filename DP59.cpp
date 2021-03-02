#include <bits/stdc++.h>
using namespace std;

//printing all posiible subset of the given array.
//o(n(n^2))

class subset
{
public:
    void printSubset(char *arr, int n)
    {
        unsigned int pow_set = pow(2, n);
        for (int i = 0; i < pow_set; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    cout << arr[j]<<" ";
                }
            }
        }
    }
};

int main()
{
    subset s;
    char arr[] = {'a', 'b', 'c'};
    int n = sizeof(arr) / sizeof(arr[0]);
    s.printSubset(arr, n);
    return 0;
}
