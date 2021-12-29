
#include <bits/stdc++.h>
using namespace std;


class Solution {

public:
    int minOperations(string X, string Y)
    {
        int n = X.size(), m = Y.size();
        //*  initilization
        int t[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < m + 1; j++)
                if (i == 0 || j == 0) t[i][j] = 0;

        //* computation
        for (int i = 1; i < n + 1; i++)
            for (int j = 1; j < m + 1; j++) {
                if (X[i - 1] == Y[j - 1]) t[i][j] = 1 + t[i - 1][j - 1];
                else t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        //* Take the Path via Lcs first convert A to only LCS by
        //* deletion and then convert That Lcs to B by insertion
        //* Deletion :- n- LCS
        //* Insertion :- m-LCS;
        return n + m - (2 * t[n][m]);
    }

};

// { Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        cout << ob.minOperations(s1, s2) << "\n";

    }
    return 0;
}

// } Driver Code Ends