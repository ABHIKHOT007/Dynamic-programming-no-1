#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int lcslen=0;
int dp[MAX][MAX];

int lcs(string str1, string str2, int n, int m, int i, int j)
{
   int &ret=dp[MAX][MAX];

    if(i==n||j==m){
        return ret=0;
    }

    if(ret!=-1){
        return ret;
    }
    ret=0;

    if(str1[i]==str2[j]){
        ret=1+lcs(str1,str2,n,m,i+1,j+1);
    }
    else{
        ret=max(lcs(str1,str2,n,m,i+1,j),lcs(str1,str2,n,m,i,j+1));
    }
    return ret;
}

void printAllSubsequence(string str1, string str2,int n,int m, char data[], int indx1, int indx2, int currlcs)
{
    if(currlcs==lcslen){
        data[currlcs]='\0';
        puts(data);
        return;
    }

    if(indx1==n||indx2==m){
        return;
    }

    for(char ch='a';ch<='z';ch++){
        bool done=false;
        for(int i=indx1;i<n;i++){
            if(ch==str1[i]){
                for(int j=indx2;j<m;j++){
                    if(ch==str2[j]&&lcs(str1,str2,n,m,i,j)==lcslen-currlcs){
                        data[currlcs]=ch;
                        printAllSubsequence(str1,str2,n,m,data,i+1,j+1,currlcs+1);
                        done=true;
                        break;
                    }
                }
            }
            if(done){
                break;
            }
        }
    }
}

void printAllSubsequenceSorted(string str1, string str2)
{
    int n=str1.length();
    int m=str2.length();

    memset(dp,-1,sizeof(dp));
    lcslen=lcs(str1,str2,n,m,0,0);
    char data[MAX];
    printAllSubsequence(str1,str2,n,m,data,0,0,0);
}

int main()
{
    string str1="abcabcaa";
    string str2="acbacba";
    printAllSubsequenceSorted(str1,str2);
    return 0;
}