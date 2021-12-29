//--------- Raghav  Patidar---------
//? Heading :- Longest common subString


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int longestCommonSubstr(string s1, string s2, int n, int m)
    {

        int t[n + 1][m + 1];

        //*  initilization
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0) t[i][j] = 0;
            }
        }

        //* computation
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) t[i][j] = 1 + t[i - 1][j - 1];
                else t[i][j] = 0; //* if last two is not equal then we make this 
                //* substring of zero lenght this is the only change from lcs
            }
        }
        int ans = 0;
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                ans = max(t[i][j], ans);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends