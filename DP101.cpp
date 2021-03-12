#include<bits/stdc++.h>
using namespace std;

//calculating the maximum XOR value in the given L to R range.

int maxXOROperation(int L, int R)
{
    int LXR=L^R;

    int msbPos=0;

    while(LXR){
        msbPos++;
        LXR>>=1;
    }
    int maxXOR=0;
    int two=1;

    while(msbPos--){
        maxXOR+=two;
        two<<=1;
    }

    return maxXOR;
}

int main()
{
    int L=8;
    int R=20;

    cout<<maxXOROperation(L,R);
    return 0;
}