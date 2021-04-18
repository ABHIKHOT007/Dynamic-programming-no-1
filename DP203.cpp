#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int upvote = 0;
        int downvote = 0;

        if (n == 1)
        {
           if(a[0]==1){
               cout<<"1"<<"\n";
           }
           if(a[0]==2){
               cout<<"0"<<"\n";
           }
           if(a[0]==3){
               cout<<"0"<<"\n";
           }
        }

        else
        {

            for (int i = 0; i < n; i++)
            {
                if (a[i] == 1)
                {
                    upvote++;
                }
                if (a[i] == 2)
                {
                    downvote++;
                }
                if (a[i] == 3)
                {
                    if (downvote > upvote)
                    {
                        downvote++;
                    }
                    else
                    {
                        upvote++;
                    }
                }
            }
            cout << max(upvote, downvote) << "\n";
        }
    }

    return 0;
}