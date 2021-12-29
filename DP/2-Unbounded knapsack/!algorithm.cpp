//--------- Raghav  Patidar---------
// Heading :- 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int val[1, 5, 1, 2, 5];
    int wt[5, 4, 1, 2, 6];
    int w = 5;

    int dp[n + 1][w + 1];

    //initiliazation
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < w + 1; j++)
            if (i == 1 || j == 0)
                dp[i][j] = 0;
    }
    //calculation
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < w + 1; j++)
            if (j >= wt[i - 1]) dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
            else  dp[i][j] = dp[i - 1][j];

    }
    return 0;
}