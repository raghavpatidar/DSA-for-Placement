// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int
class Solution {
public:
    long long int count(int arr[], int m, int n) {

        ll dp[m + 1][n + 1];

        for (ll i = 0;i < n + 1;i++) {
            dp[0][i] = 0;
        }
        for (ll i = 0;i < m + 1;i++) {
            dp[i][0] = 1;
        }
        for (ll i = 1;i < m + 1;i++) {
            for (ll j = 1;j < n + 1;j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends