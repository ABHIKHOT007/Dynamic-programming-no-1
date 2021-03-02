#include<bits/stdc++.h>
const int MAX_CHAR=256;
using namespace std;

//Countin no of distinct subsequences of the given string possible.
//recursive apporach

unordered_set<string> sn;
/*
void DistinctSubsequence(char s[], char op[], int i, int j)
{
    if(s[i]=='\0'){
        op[j]='\0';
        sn.insert(op);
        return;
    }
    else{
        op[j]=s[i];
        DistinctSubsequence(s,op,i+1,j+1);
        DistinctSubsequence(s,op,i+1,j);
        return;
    }
}

int main()
{
    char str[]="ggg";
    int m=strlen(str);
    int n=pow(2,m)+1;
    char op[n];
    DistinctSubsequence(str,op,0,0);
    cout<<sn.size();
    sn.clear();
    return 0;
}
*/

int DistdictSequence(string str)
{
    vector<int> last(MAX_CHAR,-1);
    int n=str.length();
    int dp[n+1];
    dp[0]=1;

    for(int i=1;i<=n;i++){
        dp[i]=2*dp[i-1];
        if(last[str[i-1]]!=-1){
            dp[i]=dp[i]-dp[last[str[i-1]]];
        }
        last[str[i-1]]=(i-1);
    }
    return dp[n];
}

int main()
{
    cout<<DistdictSequence("GFG");
    return 0;
}