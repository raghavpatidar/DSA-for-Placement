class Solution {
public:

    int mySqrt(long long  x) {
        long long  l = 0, r = x;
        long long  ans = 0;
        while (l <= r) {
            long long m = (l + r) / 2;

            if (m * m <= x) {
                ans = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return ans;

    }
};