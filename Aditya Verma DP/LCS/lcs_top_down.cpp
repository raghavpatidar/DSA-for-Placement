//--------- Raghav  Patidar---------
//? Heading :- Longest common subsequence MEMOIZATION code

#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];


int LCS(string x, string  y, int n, int m) {

    //*  initilization
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i == 0 || j == 0) t[i][j] = 0;

    //* computation
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            if (x[i - 1] == y[i - 1]) t[i][j] = 1 + t[i - 1][j - 1];
            else t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    return t[n][m];
}

int main()
{
    string x, y;
    int n, m;
    cin >> n >> m >> x >> y;
    memset(t, -1, sizeof(t));
    cout << LCS(x, y, n, m) << endl;
    return 0;
}