#include<bits/stdc++.h>
using namespace std;

//No of consecutive onec's in the given binary string.

//O(N)


int CountConsecutiveOnces(int NUM)
{
    int count_of_onces=0;
    while(NUM>0){
        NUM=NUM&(NUM<<1);
        count_of_onces++;
    }
    return count_of_onces;
}

int main()
{
    int NUM=12;
    cout<<CountConsecutiveOnces(NUM);
    return 0;
}