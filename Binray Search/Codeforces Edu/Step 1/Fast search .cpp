//--------- Raghav  Patidar---------
//Fuck Ratings, I'm in Love with Experience. 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pll pair<ll,ll>
#define vpll vector<pll>
#define cendl cout<<endl;
#define sz(x) x.size()
#define fo(i,n) for(ll i=0;i<n;i++)
#define rfo(i, n) for(ll i=n-1;i>=0;i--)
#define ff(a,n) for(int i = a;i<n;i++)
#define rf(a,n) for(int i = n-1;i>=a;i--)
#define fa(i , a) for(auto i:a)
#define asort(a) sort(a.begin() , a.end())
#define dsort(a) sort(a.begin() , a.end() , greater<int>())
#define pb push_back
#define imax INT_MAX
#define imin INT_MIN
#define lmax LONG_MAX
#define lmin LONG_MIN
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define vll vector<ll>
#define m(a) map<a,a>
#define all(v)    v.begin() , v.end()
#define pi 3.14159265358979323846264338327950288419716939937510582097494459230
#define mod 1000000007
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define tstart time_t strt, endt;time(&strt);ios_base: :sync_with_stdio(false);
#define tend time(&endt);double time_taken = double(endt - strt);cout <<endl<< fixed<< time_taken << setprecision(5)<<endl;
void input(int arr[], int n) { fo(i, n) cin >> arr[i]; }
void input(vll& v) { fo(i, v.size()) cin >> v[i]; }
void input(vector<int>& v) { fo(i, v.size()) cin >> v[i]; }
void input(vll& v, int n) { fo(i, n) { int x;cin >> x;v.pb(x); } }
void input(vector<int>& v, int n) { fo(i, n) { int x;cin >> x;v.pb(x); } }


void king() {
    int n;cin >> n;
    vll v;
    input(v, n);
    asort(v);
    int k;cin >> k;
    while (k--)
    {
        int l, r;cin >> l >> r;
        int ans1 = -1, ans2 = -1;
        int s = 0, e = n - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            // cout << s << " " << e<<" "<<mid << endl;
            if (v[mid] >= l) {
                ans1 = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        int  start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (v[mid] <= r) {
                ans2 = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        // cout << ans1 << " " << ans2 << endl;
        if (l == r) {
            cout << max(ans2 - 1, 0);
        }
        else if (ans1 == -1 && ans2 == -1) {
            cout << n << " ";
        }
        else if (ans1 == -1) {
            cout << ans2 + 1 << " ";
        }
        else if (ans2 == -1) {
            cout << n - ans1 + 1 << " ";
        }
        else {
            cout << abs(ans1 - ans2) + 1 << " ";
        }

    }

}
int main()
{
    //debugjudge();
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        king();
    }
    return 0;
}