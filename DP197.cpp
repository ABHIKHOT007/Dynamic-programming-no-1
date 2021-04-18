#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
	int n, k;
	int a[50];
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	} 
	
	 
	sort(a, a + n);
	
	
	
	if(n- k >= 0)
	{
		cout << a[n - k] << " 0" << endl;
	}
	
	else
	{
		cout << -1 << endl;
	}
 
    return 0;
}