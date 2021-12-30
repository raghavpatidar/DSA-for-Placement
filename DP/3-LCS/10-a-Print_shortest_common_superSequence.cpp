//--------- Raghav  Patidar---------
//? Heading :- Shortest  common Super subsequence 
//todo Statement :- find the shortest subseqence length  which contain both X and Y as subsequence 
#include <bits/stdc++.h>
using namespace std;
int  t[1001][1001];
void LCS(string x, string  y, int n, int m) {
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
            if (i == 0 || j == 0) t[i][j] = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++) {
            if (x[i - 1] == y[j - 1]) t[i][j] = 1 + t[i - 1][j - 1];
            else t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
}
string printLCS(string x, string y, int n, int m) {
    LCS(x, y, n, m);
    string s = "";
    int j = m, i = n;
    while (i > 0 and j > 0)
    {
        if (x[i - 1] == y[j - 1]) {
            s += x[i - 1];
            i--, j--;
        }
        else {
            if (t[i - 1][j] > t[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}
string shortestCommonSupersequence(string str1, string str2) {
    string lcs = printLCS(str1, str2, str1.size(), str2.size());
    int i = 0, j = 0;
    string ans = "";
    int k = 0;
    while (i < str1.size() and j < str2.size()) {
        if (str1[i] == lcs[k] && str2[j] == lcs[k]) {
            ans.push_back(str1[i]);
            k++, i++, j++;
        }
        else if (str1[i] == lcs[k]) {
            ans.push_back(str2[j]);
            j++;
        }
        else if (str2[j] == lcs[k]) {
            ans.push_back(str1[i]);
            i++;
        }
        else {
            ans.push_back(str1[i]);
            ans.push_back(str2[j]);
            i++, j++;
        }
    }
    while (i < str1.size()) {
        ans.push_back(str1[i]);
        i++;
    }
    while (j < str2.size()) {
        ans.push_back(str2[j]);
        j++;
    }
    return ans;
}
int main()
{
    string x, y;
    int n, m;
    cin >> n >> m >> x >> y;
    cout << shortestCommonSupersequence(x, y) << endl;
    return 0;
}