#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define pb push_back
#define mp make_pair
#define pi pair<int,int> 
#define pl pair<lli,lli>
const int mod=1e+7;

/*
void solve(int a, int b)
{
    a=a^b;
    b=a^b;
    a=a^b;

    cout<<a<<"<="<<b<<"\n";
}

void swap(char a, char b)
{
    char temp=a;
    a=b;
    b=temp;
    cout<<a<<"<="<<b<<"\n";
}


void isEvenOddmathatical(int n)
{
    if((n%2)==0){
        cout<<"yes"<<"\n";
    }
    else{
        cout<<"no"<<"\n";
    }
}

void isEvenOddBitmask(int n)
{
    if((n&1)==0){
        cout<<"yes"<<"\n";
    }
    else{
        cout<<"no"<<"\n";
    }
}
*/

void leeftshift(int  n)
{
    int ans=n<<1;
    cout<<ans<<"\n";
}

void rightShift(int n)
{
    int ans=n>>1;
    cout<<ans<<"\n";

}

/*
int CD(int n)
{
    while(n){
        cnt++;
        n/=10;
    }
    return cnt;
}*/

int main()
{
    /*int a,b;
    cin>>a>>b;
    char x,y;
    cin>>x>>y;
    cout<<a<<"=>"<<b<<"\n";
    solve(a,b);
    cout<<x<<"=>"<<y<<"\n";
    swap(x,y);*/

    int n;
    cin>>n;
    //isEvenOddmathatical(n); 
    //isEvenOddBitmask(n);
    cout<<"rightshift"<<"\n";
    rightShift(n);
    cout<<"leftshift"<<"\n";
    leeftshift(n); 
    return 0; 
}