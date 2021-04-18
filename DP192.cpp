#include<bits/stdc++.h>
using namespace std;


int swap(char *x, char *y)
{
    int temp=*x;
    *x=*y;
    temp=*y;
    
}

void permute(char *a, int l, int r)
{
    int i;
    if(i==l){
        cout<<a<<"\n";
    }
    else{
        for(int i=l;i<r;i++){
            swap((a+l),(a+i));
            permute(a,l+1,r);
            swap((a+l),(a+i));
        }
    }
}

int main()
{
    char str[]="ABC";
    int n=strlen(str);
    permute(str,0,n-1);
    return 0;
}