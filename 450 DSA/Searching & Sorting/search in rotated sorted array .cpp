//--------- Raghav  Patidar---------
//Fuck Ratings,Just Enjoy the Contest 
//I'm in Love with Experience. 
#include <bits/stdc++.h>


using namespace std;
#define ll long long  
#define int long long 
#define pb push_back 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)



class Solution {
public:
    int search(vector<int>& v, int x) {
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;

            if (v[m] == x) {
                return m;
            }

            // left part is sorted 
            if (v[l] <= v[m]) {
                if (v[l] <= x && x <= v[m]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            else {
                if (v[m] <= x && x <= v[r]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    //debugjudge();
    fast;
    int tests = 1;
    return 0;
}