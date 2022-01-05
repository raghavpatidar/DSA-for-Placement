//--------- Raghav  Patidar---------
// Heading :- 

#include <bits/stdc++.h>
using namespace std;

int n;

int MCM(int arr[], int i, int j) {
    //Base Condition
    if (i >= j)
        return 0;
    //min ans
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        //calculatign temp ans
        int tempans =
            MCM(arr, i, k) // ans form part between i to k
            + MCM(arr, k + 1, j) // answer form part between k+1 to j 
            + (arr[i - 1] * arr[k] * arr[j]); // calculating addition of part first and seocnd
        ans = min(ans, tempans); // updating main ans with min answer btween itself or tempanswe;
    }
    return ans;//returnning final answer;
}

int main()
{
    cin >> n;
    int arr[n];
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    return 0;
}