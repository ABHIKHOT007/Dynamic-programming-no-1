#include<bits/stdc++.h>
using namespace std;

inline int gcd(int x, int y)
{
    if(x>y) swap(x,y);
    while(x){
        y%=x;
        swap(x,y);
    }
    return y;
}

int cnt=0;
int CNOD(int n)
{
    cnt=(n==0)?1:(log10(n)+1);
    return cnt;
}

int main()
{
    int t=1;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        a-=c,b-=c;
        int x=1,y=1,z=1;
        for(int i=1;i<=a;i++){
            x*=10;
        }
        for(int i=1;i<=b;i++){
            y*=10;
        }
        for(int i=1;i<c;i++){
            z*=10;
        }
        int p=x;
        while(gcd(x,y)>9){
            ++x;
            if(x==p*10){
                x=p;
                ++y;
            }
        }
        cout<<x*z<<" "<<y*z<<"\n";
    }
    return 0;
}
