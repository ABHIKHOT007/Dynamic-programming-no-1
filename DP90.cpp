#include<bits/stdc++.h>
using namespace std;

//Count no of binary string without consecuitive one's.

int CountBinaryString(int N)
{
    //String of length i ending with 0.
    int one[N];
    //String of length i ending with 1.

    int zero[N];

    zero[0]=1;
    one[0]=1;

    if(N==0||N==1){
        return 0;
    }

    for(int i=1;i<=N;i++){
        zero[i]=zero[i-1]+one[i-1];
        one[i]=zero[i-1];
    }

    //Addition of both will be the total no strings.

    return zero[N-1]+one[N-1];
}


int main()
{
    int N=3;
    cout<<CountBinaryString(N);
    return 0;
}