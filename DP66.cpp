#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int LCSlen=0;
int dp[MAX][MAX];

int LCS(string str1,string str2, int n, int m, int i, int j)
{
    int &ret=dp[i][j];

    if(i==n||j==m){
        return ret=0;
    }

    if(ret!=-1){
        return ret;
    }

    ret=0;

    if(str1[i]==str2[j]){
        ret=1+LCS(str1,str2,n,m,i+1,j+1);
    }
    else{
        ret=max(LCS(str1,str2,n,m,i+1,j),LCS(str1,str2,n,m,i,j+1));
    }

    return ret;
}

void printAllStrings(string str1, string str2, int n, int m, char data[], int idx1, int idx2, int curr)
{
    if(curr=LCSlen){
        data[curr]='\0';
        puts(data);
        return;
    }

    if(idx1==n||idx2==m){
        return;
    }

    for(char ch='a';ch<='z',ch++){
        bool done=false;
        for(int i=idx1;i<n;i++){
            if(ch==str1[i]){
                for(int j=idx2;j<m;j++){
                    if(ch==str2[j]&&LCS(str1,str2,n,m,i,j)==LCSlen-curr){
                        data[curr]=ch;
                        printAllStrings(str1,str2,n,m,data,i+1,j+1,curr+1);
                        done=true;
                        break;
                    }
                }
            }
        }
        if(done){
            break;
        }
    }
}

void printallSeucene(string str1, string str2)
{
    int n=str1.length();
    int m=str2.length();

    memset(dp,-1,sizeof(dp));
    LCSlen=LCS(str1,str2,n,m,0,0);
    char data[MAX];

    char data[MAX];
    printallSeucene(str1,str2,n,m,0,0,0); 
}

int main()
{
    string str1="abcabbaa";
    string str2="acbcaba";
    printallSeucene(str1,str2)
}