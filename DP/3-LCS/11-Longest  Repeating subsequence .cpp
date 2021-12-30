
// concept :- LCS given one string make a copy into anothert string and fo lcs
//            with one more condition if the i == j then we will not add that character into out subsequece
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int LongestRepeatingSubsequence(string x) {

        int n = x.size();
        int m = n;
        //! making copy x into y
        string y = x;
        int t[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < m + 1; j++)
                if (i == 0 || j == 0) t[i][j] = 0;

        //* computation
        for (int i = 1; i < n + 1; i++)
            for (int j = 1; j < m + 1; j++) {
                //! we add one new condition i!=j
                if (i != j && x[i - 1] == y[j - 1]) t[i][j] = 1 + t[i - 1][j - 1];
                else t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        return t[n][m];
    }

};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
}