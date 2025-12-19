// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

// Constraints:

// 0 <= x <= 231 - 1

class Solution {
public:
    int mySqrt(int x) {
        int lo = 0;
        int hi = x;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long m = (long long)mid;
            long long y = (long long)x;

            if ((m * m) == y)
                return mid;
            else if (m * m > y)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return hi;
    }
};
