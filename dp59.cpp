#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

//maximum sum int path by not taking any adjicent elements
int maxSum(int arr[2][MAX], int n)
{
    int incl=max(arr[0][0],arr[1][0]);
    int excl=0;
    int excl_new;

    for(int i=1;i<n;i++){
        excl_new=max(excl,incl);

        incl=excl+max(arr[0][i],arr[1][i]);

        excl=excl_new;
    }
    return max(excl,incl);
}

int main()
{
    int arr[2][MAX]={{1,2,3,4,5},{6,7,8,9,10}};
    int n=5;
    cout<<maxSum(arr,n);
    return 0;
}