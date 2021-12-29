/*
*--------- Raghav  Patidar---------

! MY approaxch
 todo    Heading :- find the minimum no of coin required fron coin[] with size m
 todo    which give value of  sum and if no valid ans possible return -1
 initilization
         0 1  2 ......(sum+1)
     0   0 -1 -1 -1 -1 -1
     1   0  -  -  -  -  -
     2   0  -  -  -  -  -
     .   0  -  -  -  -  -
     .   0  -  -  -  -  -
 (m+1)   0  -  -  -  -  -
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCoins(int coin[], int m, int sum)
    {
        int t[m + 1][sum + 1];
        //* initilization
        for (int i = 0;i < sum + 1;i++)t[0][i] = -1;
        for (int i = 0;i < m + 1;i++)t[i][0] = 0;
        //* dp calculation
        for (int i = 1;i < m + 1;i++) {
            for (int j = 1;j < sum + 1;j++) {
                if (coin[i - 1] <= j) {
                    //is possible
                    int x = t[i][j - coin[i - 1]]; // including the coin
                    int y = t[i - 1][j]; // not including the coin
                    if (x != -1 && y != -1)
                        t[i][j] = min(x + 1, y);
                    else if (x != -1)
                        t[i][j] = x + 1;
                    else
                        t[i][j] = y;
                }
                else t[i][j] = t[i - 1][j];
            }
        }
        return t[m][sum];
    }

};

// { Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for (int i = 0; i < m; i++)
            cin >> coins[i];


        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";

    }
    return 0;
}
// } Driver Code Ends


/*
 ! Aditya verma approach



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCoins(int coin[], int m, int sum)
    {
        int t[m + 1][sum + 1];
        //* initilization
        for (int i = 0;i < sum + 1;i++)t[0][i] = INT_MAX - 1;
        for (int i = 0;i < m + 1;i++)t[i][0] = 0;
        for (int i = 1; i < sum + 1; i++) {
            if (i % coin[0] == 0)t[1][i] = i / coin[0];
            else t[1][i] = INT_MAX - 1;
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (coin[i - 1] <= j)
                {
                    t[i][j] = min(1 + t[i][j - coin[i - 1]], t[i - 1][j]);
                }
                else {
                    t[i][j] = t[i - 1][j];
                }
            }

        }
        return t[m][sum] == INT_MAX ? -1 : t[m][sum];
    }

};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for (int i = 0; i < m; i++)
            cin >> coins[i];


        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";

    }
    return 0;
}

*/

