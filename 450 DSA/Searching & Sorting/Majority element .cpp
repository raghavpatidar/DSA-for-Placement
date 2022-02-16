// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // Function to find majority element in the array
   // a: input array
   // size: size of input array
    int majorityElement(int a[], int size)
    {

        int idx = 0, ctr = 1, n = size;
        for (int i = 0;i < n;i++) {
            if (a[idx] == a[i])ctr++;
            else ctr--;
            if (ctr == 0) {
                idx = i;
                ctr = 1;
            }
        }
        int check = 0;
        for (int i = 0;i < n;i++) {
            if (a[i] == a[idx])check++;
        }

        if (check > size / 2)return a[idx];
        else return -1;

    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0;i < n;i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
// } Driver Code Ends