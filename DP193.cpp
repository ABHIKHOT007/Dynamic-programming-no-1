#include<bits/stdc++.h>
using namespace std;
/*
int len;
int string[200];
int main()
{
    int i,j;
    i=1;
    for(i=1;;i++)
    {
        scanf("%c",&string[i]);
        if((string[i]>='A'&&string[i]<='Z')||(string[i]>='a'&&string[i]<='z'))
        continue;
        else
        break;
    }
    len=i-1;
    for(i=1;i<=len;i++)
    {
        if(string[i]=='a'||string[i]=='e'
           ||string[i]=='i'||string[i]=='o'
           ||string[i]=='u'||string[i]=='y'
           ||string[i]=='A'||string[i]=='E'
           ||string[i]=='I'||string[i]=='O'
           ||string[i]=='U'||string[i]=='Y')
        continue;
        printf(".");
        if(string[i]>='A'&&string[i]<='Z')
        printf("%c",string[i]-'A'+'a');
        else
        printf("%c",string[i]);
    }
    return 0;
}
*/


int main()
{
    string str="tour";

    transform(str.begin(),str.end(),str.begin(),::toupper);
    cout<<"upper case:"<<str;

    transform(str.begin(),str.end(),str.begin(),::tolower);
    cout<<"lower case:"<<str;

    return 0;
}