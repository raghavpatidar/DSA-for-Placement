// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[101][101];
    int MCM(int arr[], int i, int j) {
        //Base Condition
        if (i >= j)
            return 0;
        //min ans
        if (t[i][j] != -1)return t[i][j];
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
        return t[i][j] = ans;//returnning final answer;
    }

    int matrixMultiplication(int N, int arr[])
    {
        memset(t, -1, sizeof(t));
        return MCM(arr, 1, N - 1);
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0;i < N;i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}