#include<bits/stdc++.h>
using namespace std;
//o(n^2)
/*
int maxBalanced(char str[], int n)
{
    int dp[n][n];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<n-1;i++){
        if(str[i]=='(' && str[i+1]==')'){
            dp[i][i+1]=2;
        }
    }

    for(int l=2;l<n;l++){
        for(int i=0,j=l;j<n;i++,j++){
            if(str[i]=="(" && str[j]==")"){
                dp[i][j]=2+dp[i+1][j-1];
            }

            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }

    return dp[0][n-1];
}
*/

int maxBalanced(char str[], int n)
{
    int validPosOpen=0;
    int validClosed=0;

    for(int i=0;i<n;i++){
        if(str[i]=='('){
            validPosOpen++;
        }
        else{
            if(validClosed==0){
                validClosed++;
            }
            else{
                validPosOpen--;
            }
        }
    }
    return n-((validPosOpen)+(validClosed));
}


int main()
{
    char str[]="()()((((()";
    int n=strlen(str);
    cout<<maxBalanced(str,n);
    return 0;
}