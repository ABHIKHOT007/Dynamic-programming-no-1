#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int arr[6][6];
    int r,c;

    for(int i=1;i<6;i++){
        for(int j=1;j<6;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                r=abs(3-i);
                c=abs(3-j);
                cout<<r+c<<"\n";
            }
        }
    }

    return 0;
}