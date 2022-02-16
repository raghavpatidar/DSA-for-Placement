// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, n;
        cin >> l >> n;
        int arr[l];
        for (int i = 0;i < l;i++)
            cin >> arr[i];
        if (findPair(arr, l, n))
            cout << 1 << endl;
        else cout << "-1" << endl;
    }


    return 0;
}// } Driver Code Ends


bool check(int arr[], int target, int n) {
    // cout<<target<<endl;
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        // cout<<l<<" "<<r<<endl;
        if (arr[m] == target)return true;
        else if (arr[m] < target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    // cout<<target<<endl;
    return false;
}

bool findPair(int arr[], int n, int x) {
    sort(arr, arr + n);
    for (int i = 0;i < n;i++) {
        int y = x + arr[i];
        if (check(arr, abs(y), n) == true)return true;
        // if(check(arr , -y , n))return true;
    }
    return false;
}