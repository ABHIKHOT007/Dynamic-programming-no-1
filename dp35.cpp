#include<bits/stdc++.h>
#define MAX 100
#define MAX_CHAR 26
using namespace std;

//Number of palidromic subsequences of the length k.


void precomute(string s, int n, int left[][MAX], int right[][MAX])
{
    left[s[0]-'a'][0]=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<MAX_CHAR;j++){
            left[j][i]+=left[j][i-1];
        }
        left[s[i]-'a'][i]++;
    }
    right[s[n-1]-'a'][n-1]=1;

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<MAX_CHAR;j++){
            right[j][i]+=right[j][i+1];
        }
        right[s[i]-'a'][i]++;
    }
}

int countPalidrome(int k,int n,int left[][MAX], int right[][MAX])
{
    int ans=0;
    if(k==1){
        for(int i=0;i<MAX_CHAR;i++){
            ans+=left[i][n-1];
        }
        return ans;
    }
    if(k==2){
        for(int i=0;i<MAX_CHAR;i++){
            ans+=((left[i][n-1])*(left[i][n-1])/2);
        }
        return ans;
    }

    for(int i=1;i<n-1;i++){
        for(int j=0;j<MAX_CHAR;j++){
            ans+=left[j][i-1]*right[j][i+1];
        }
    }
    return ans;
}


int main()
{
    string str="aabab";
    int k=2;
    int n=str.length();
    int left[MAX_CHAR][MAX]={0};
    int right[MAX_CHAR][MAX]={0};
    precomute(str,n,left,right);
    cout<<countPalidrome(k,n,left,right)<<"\n";
    return 0;
}
