//--------- Raghav  Patidar---------
//?  Heading :- Printing Longest common subsequence MEMOIZATION code
//todo This conde is based on the aditya verma DP concept 


#include <bits/stdc++.h>
using namespace std;

//* making the dp of string to get the required string directly
string static t[1001][1001];


string  LCS(string x, string  y, int n, int m) {

    //*  initilization complete table with empty string 
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
            t[i][j] = "";

    //* computation
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++) {
            //* if two character are equal then we directly add that character to the (i-1 , j-1) th positon string
            if (x[i - 1] == y[j - 1]) t[i][j] = t[i - 1][j - 1] + x[i - 1];
            //* otherwise we will make t[i][j] equal to the max of prevoius two string (i-1,j)th or (i,j-1)th
            else {
                string a = t[i - 1][j];
                string b = t[i][j - 1];
                if (a.size() > b.size()) {
                    t[i][j] = a;
                }
                else {
                    t[i][j] = b;
                }
            }
        }
    // returning the final max string after full computation
    return t[n][m];
}


int main()
{
    string x, y;
    int n, m;
    cin >> x >> y;
    n = x.size();
    m = y.size();
    cout << n << " " << m << endl;
    cout << LCS(x, y, n, m) << endl;
    return 0;
}