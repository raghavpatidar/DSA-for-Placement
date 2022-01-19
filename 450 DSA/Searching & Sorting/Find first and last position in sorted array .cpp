//--------- Raghav  Patidar---------
//Fuck Ratings,Just Enjoy the Contest 
//I'm in Love with Experience. 
#include <bits/stdc++.h>


using namespace std;
#define ll long long  
#define int long long 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
bool debugg = false;
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << "'" << x << "'"; }
void __print(const char* x) { cerr << '"' << x << '"'; }
void __print(const string& x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) { cerr << '(';__print(x.first); cerr << ',';__print(x.second);cerr << ')'; }
template <typename T>
void __print(const T& x) { int f = 0;cerr << '[';for (auto& i : x)cerr << (f++ ? "," : ""), __print(i);cerr << "]"; }
void _print() { cerr << "]"; cerr << endl; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
#define debArr(arr) if (debugg){cerr << #arr << " : [";fa(itr, arr) cerr << itr << " ,";cerr << " ]";cerr<<endl;}
#define debMap(mp) if(debugg){cerr<<#mp<<endl;repla(itr,mp) cerr<<"{"<<itr.first<<", "<<itr.second<<"}";cerr<<endl;}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [";  _print(x)
#else
#define debug(x...)
#endif
void debugjudge() {
#ifndef ONLINE_JUDGE
    debugg = true;
    // debugg = false;
#endif
}

class Solution {
public:
    vector<int> searchRange(vector<int>& v, int target) {
        vector<int>ans;
        if (v.empty()) {
            ans.pb(-1);
            ans.pb(-1);
            return ans;
        }
        if (v.size() == 1) {
            if (v[0] == target) {
                ans.pb(0);
                ans.pb(0);
                return ans;
            }
            else {
                ans.pb(-1);
                ans.pb(-1);
                return ans;
            }
        }
        int mi = -1;
        int l = 0, r = v.size() - 1;
        bool check = false;
        while (l <= r) {
            int m = (l + r) / 2;
            if (v[m] == target) { check = true;break; }
            else if (v[m] < target)l = m + 1;
            else r = m - 1;
        }

        if (check == false) { ans.pb(-1), ans.pb(-1);return ans; }

        l = 0, r = v.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (v[m] < target) {
                l = m + 1;
                mi = m;
            }
            else {
                r = m - 1;
            }
        }
        // debug(mi);
        if (mi == -1) {
            if (v.size() > 0 && v[0] == target) ans.pb(0);
            else ans.pb(-1);
        }
        else ans.pb(mi + 1);


        int ma = -1;


        l = 0, r = v.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (v[m] > target) r = m - 1, ma = m;
            else l = m + 1;
        }

        // debug(ma);
        if (ma == -1)
            if (v.size() > 0 && v[v.size() - 1] == target) { ans.pb(v.size() - 1); }
            else { ans.pb(-1); }
        else  ans.pb(ma - 1);

        return ans;
    }
};




int32_t main()
{
    //debugjudge();
    fast;
    int tests = 1;
    Solution ob;
    int n, target;
    cin >> n >> target;
    vector<int>v;
    for (int i = 0;i < n; i++) {
        int x;cin >> x;
        v.pb(x);
    }

    vector<int> ans = ob.searchRange(v, target);
    for (int i = 0;i < 2;i++) {
        cout << ans[i] << " ";
    }
    // debug(ans);
    // cin >> tests;
    // for (int tt = 1; tt <= tests; tt++)
    //     king(tt);
    return 0;
}