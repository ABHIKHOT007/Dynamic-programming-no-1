#include <bits/stdc++.h>
using namespace std;

//newman-conways sequence.
/*p(n)=p(p(n-1))+p(n-p(n-1))

int newmanconway(int n)
{
    if (n < 1)
    {
        return 0;
    }

    if (n == 1 || n == 2)
    {
        return 1;
    }

    return newmanconway(newmanconway(n - 1)) + newmanconway(n - newmanconway(n - 1));
}

void printsolution(int n)
{
    for (int i = 3; i <= n; i++)
    {
        cout << newmanconway(i) << " ";
    }
}
*/

int newmanconway(int n)
{
    int f[n+1];
    int i;
    f[0]=0;
    f[1]=f[2]=1;
    for(int i=3;i<=n;i++){
        f[i]=f[f[i-1]]+f[n-f[i-1]];
    }
    return f[n];
}

int main()
{
    int n = 10;
    cout << "newman-conways sequence is:" << newmanconway(n) << "\n";
    return 0;
}