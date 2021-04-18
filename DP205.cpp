#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cerr<<#x<<" = "<<x<<endl

string s;

int main(){
    ios::sync_with_stdio(false);

    int T;cin>>T;
    while(T--){
        int a,b;cin>>a>>b>>s;
        bool f=true;
        int n=s.length();
        int A=0,B=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') A++;
            else if(s[i]=='1') B++;
        }
        if(A>a||B>b){
            cout<<"-1\n";
            continue;
        }
        for(int i=0;i<n/2;i++){
            if(s[i]=='?'&&s[n-1-i]=='?') continue;
            else if(s[i]=='?'){
                if(s[n-1-i]=='0'){
                    a-=2;s[i]='0';
                }
                else{
                    b-=2;s[i]='1';
                }
            }
            else if(s[n-1-i]=='?'){
                if(s[i]=='0'){
                    a-=2;s[n-1-i]='0';
                }
                else{
                    b-=2;s[n-1-i]='1';
                }
            }
            else{
                if(s[i]!=s[n-1-i]) f=false;
                else if(s[i]=='0') a-=2;
                else b-=2;
            }
        }
        if(n&1){
            int t=n/2;
            if(s[t]=='?'){
                if(a&1){
                    --a;s[t]='0';
                }
                else{
                    --b;s[t]='1';
                }
            }
            else if(s[t]=='0') a--;
            else b--;
        }
        if((a&1)&&(b&1)) f=false;
        for(int i=0;i<n/2;i++){
            if(s[i]=='?'){
                if(a>0){
                    s[i]=s[n-1-i]='0';
                    a-=2;
                }
                else{
                    s[i]=s[n-1-i]='1';
                    b-=2;
                }
            }
        }
        if(a<0||b<0) f=false;
        if(f) cout<<s<<"\n";
        else cout<<"-1\n";
    }
}
