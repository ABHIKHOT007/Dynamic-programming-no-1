#include <bits/stdc++.h>
using namespace std;

//tilling the 3*n dominoes with 2*1 dominose.

int countnoways(int n)
{
    int A[n+1];
    int B[n+1];

    A[0]=1;
    A[1]=0;
    B[0]=0;
    B[1]=1;

    for(int i=2;i<=n;i++){
        A[i]=A[i-2]+2*B[i-1];
        B[i]=A[i-1]+B[i-2];
    }
    return A[n];
}

int main()
{
    int n = 8;
    cout << "No of ways are:" << countnoways(n) << "\n";
    return 0;
}