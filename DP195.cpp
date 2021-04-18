#include<bits/stdc++.h>
using namespace std;

string a,b;

int main()
{
    cin>>a>>b;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<a.size();i++){
        if(a[i]<92){
            a[i]+=32;
        }
        if(b[i]<92){
            b[i]+=32;
        }
    }

    if(a<b){
        cout<<-1;
    }
    else if(a>b){
        cout<<1;
    }
    else if(a==b){
        cout<<0;
    }

    return 0;
}



//2nd solution

#include<bits/stdc++.h>
using namespace std;

string a,b;

int solve(string a, string b)
{
    int cnt=0;

    for(int i=0;i<a.length();i++){
        if(tolower(a[i])>tolower(b[i])){
            return 1;
        }
        else if(tolower(a[i])<tolower(b[i])){
            return -1;
        }
        else{
            cnt++;
        }
    }

    if(cnt==a.length()){
        return 0;
    }
}

int main()
{
    string a,b;
    cin>>a>>b;

    cout<<solve(a,b);
    return 0;
}