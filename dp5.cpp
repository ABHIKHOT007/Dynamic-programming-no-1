#include <bits/stdc++.h>
using namespace std;
/*
unsigned long int catalan(unsigned int n)
{
    if(n<=1){
        return 1;
    }

    unsigned long int res=0;
    for(int i=0;i<n;i++){
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}

int main()
{
    int n=10;
    for(int i=0;i<n;i++){
        cout<<catalan(i)<<" ";
    }
    return 0;
}
*/

unsigned long int catalandp(unsigned int n)
{
    unsigned long int catalan[n+1];
    catalan[0]=catalan[1]=1;

    for(int i=2;i<=n;i++){
        catalan[i]=0;
        for(int j=0;j<n;j++){
            catalan[i]+=catalan[j]*catalan[i-j-1];
        }
    }
    return catalan[n];
}

int main()
{
    for(int i=0;i<10;i++){
        cout<<catalandp(i)<<" ";
    }
    return 0;
}