#include<bits/stdc++.h>
using namespace std;

int main()
{
    bitset<4> bset1(19);
    bitset<4> bset2(3);
    //Comparasion operator.

    cout<<(bset1==bset2)<<"\n";
    cout<<(bset1!=bset2)<<"\n";

    //bitwise operator.

    cout<<(bset1^=bset2)<<"\n";
    cout<<(bset1&=bset2)<<"\n";
    cout<<(bset1!=bset2)<<"\n";

    //left and right shift operation.

    cout<<(bset1<<2)<<endl;
    cout<<(bset1>>=1)<<endl;

    cout<<(~bset2)<<"\n";

    cout<<(bset1&bset2)<<endl;
    cout<<(bset1|bset2)<<endl;
    cout<<(bset1^bset2)<<endl;

    return 0;


}