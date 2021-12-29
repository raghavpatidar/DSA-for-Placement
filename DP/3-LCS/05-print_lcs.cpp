//--------- Raghav  Patidar---------
//?  Heading :- Printing Longest common subsequence MEMOIZATION code
//todo This conde is based on the aditya verma DP concept 


#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];


void LCS(string x, string  y, int n, int m) {

    //*  initilization
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
            if (i == 0 || j == 0) t[i][j] = 0;

    //* computation
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++) {
            if (x[i - 1] == y[j - 1]) t[i][j] = 1 + t[i - 1][j - 1];
            else t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    cout << t[n][m] << endl;
}
string printLCS(string x, string y, int n, int m) {
    string s = "";
    //*intitial at the end of the metrix and moving upside to find the lcs string
    int j = m, i = n;

    while (i > 0 and j > 0)
    {
        // if two character at ith and jth position are
        // equal then we simple add them to our resultant string
        if (x[i - 1] == y[j - 1]) {
            s += x[i - 1];
            i--, j--;
        }
        // else we will to the position where we came for example
        // in matrix we have two choice from where we came if two character
        // are not equal at ith position then we simple move to their parent 
        // so we can either move to t[i-1][j] or t[i][j-1] or which is max we go to there
        else {
            //cheacking max conditon for parent 
            if (t[i - 1][j] > t[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    string x, y;
    int n, m;
    // cin >> n >> m >> x >> y;
    cin >> x >> y;
    n = x.size();
    m = y.size();
    LCS(x, y, n, m);
    cout << printLCS(x, y, n, m) << endl;
    return 0;
}