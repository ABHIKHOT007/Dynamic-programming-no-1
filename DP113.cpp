#include <bits/stdc++.h>
using namespace std;

//Triplate sum in array.
//O(N^3)

/*
void TriplateSum(int arr[], int n, int sum)
{
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==sum){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<"\n";
                }
            }
        }
    }
}
*/

//O(N^2)
//O(1)

/*
void TriplateSum(int arr[], int n, int sum)
{
    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++)
    {
        int start = i + 1;
        int end = n - 1;
        while (start < end)
        {
            if (arr[start] + arr[i] + arr[end] == sum)
            {
                cout << arr[i] << " " << arr[start] << " " << arr[end] << "\n";
            }
            else if (arr[i] + arr[start] + arr[end] < sum)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
}
*/

//O(N)
//O(1)

void TriplateSum(int arr[], int n, int sum)
{
    for (int i = 0; i < n - 2; i++)
    {
        unordered_set<int> hash_set;
        int curr_sum = sum - arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (hash_set.find(curr_sum - arr[j]) != hash_set.end())
            {
                cout << arr[i] << " " << arr[j] << " " << curr_sum << "\n";
            }
            hash_set.insert(arr[j]);
        }
    }
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 22;
    TriplateSum(arr, n, sum);
    return 0;
}