
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<lli, lli>
#define rep(i, n) for (int i = 1; (int)i <= n; i++)
#define p pair<int, int>
const int mod=1e+7;
int max(int a, int b) {return (a>b)?a:b;}
int min(int a, int b) {return (a<b)?a:b;}

char str[200] ;
int a[30] , b[30] ;
int main()
{    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n , i ;    
    cin>>n ;    
    cin>>str;    
    memset(a,0,sizeof(a)) ;    
    memset(b,0,sizeof(b)) ;    
    for(i = 0 ; i< n ; i++)    
    {        
        if( str[i] >= 'a' && str[i]<= 'z' )            
            a[ str[i]-'a' ] = 1 ;        
        if( str[i] >= 'A' && str[i]<= 'Z' )            
            b[ str[i]-'A' ] = 1 ;    
    }    
    for(i = 0 ; i< 26 ; i++)        
        if( a[i] == 0 && b[i] == 0 )            
            break ;    
        if( i< 26 )        
            printf("NO\n") ;    
        else        
            printf("YES\n") ;    
    return 0 ;
}