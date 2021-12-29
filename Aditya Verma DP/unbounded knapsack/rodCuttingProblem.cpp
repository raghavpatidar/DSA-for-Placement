/*
?--------- Raghav  Patidar---------
* Heading :-  Rod cutting problem


!same as main algorithm  only variable name is changed
!   val[]--->price[]
!  wt[]--->length[]
!  W --> N
!rest the algorithmm and code is exactly same

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int price[1, 5, 1, 2, 5];
    int length[5, 4, 1, 2, 6];
    int N = 5;

    int dp[n + 1][N + 1];

    //initiliazation
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < N + 1; j++)
            if (i == 1 || j == 0)
                dp[i][j] = 0;
    }
    //calculation
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < N + 1; j++)
            if (j >= length[i - 1]) dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - length[i - 1]]);
            else  dp[i][j] = dp[i - 1][j];

    }
    return 0;
}


/*
gfg submission:-
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
int dp[n+1][n+1];
        vector<int>v(n);
        for(int i=1;i<=n;i++){
            v[i-1] = i;
        }
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++)if(i==0 || j==0)dp[i][j] = 0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
              if(v[i-1] <= j)dp[i][j] = max(dp[i-1][j] ,price[i-1] + dp[i][j - v[i-1]]);
              else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][n];

    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends

*/




