// You are given an integer array nums of length n.

// A trionic subarray is a contiguous subarray nums[l...r] (with 0 <= l < r < n) for which there exist indices l < p < q < r such that:

// nums[l...p] is strictly increasing,
// nums[p...q] is strictly decreasing,
// nums[q...r] is strictly increasing.
// Return the maximum sum of any trionic subarray in nums.

 

// Example 1:

// Input: nums = [0,-2,-1,-3,0,2,-1]

// Output: -4

// Explanation:

// Pick l = 1, p = 2, q = 3, r = 5:

// nums[l...p] = nums[1...2] = [-2, -1] is strictly increasing (-2 < -1).
// nums[p...q] = nums[2...3] = [-1, -3] is strictly decreasing (-1 > -3)
// nums[q...r] = nums[3...5] = [-3, 0, 2] is strictly increasing (-3 < 0 < 2).
// Sum = (-2) + (-1) + (-3) + 0 + 2 = -4.
// Example 2:

// Input: nums = [1,4,2,7]

// Output: 14

// Explanation:

// Pick l = 0, p = 1, q = 2, r = 3:

// nums[l...p] = nums[0...1] = [1, 4] is strictly increasing (1 < 4).
// nums[p...q] = nums[1...2] = [4, 2] is strictly decreasing (4 > 2).
// nums[q...r] = nums[2...3] = [2, 7] is strictly increasing (2 < 7).
// Sum = 1 + 4 + 2 + 7 = 14.
 

// Constraints:

// 4 <= n = nums.length <= 105
// -109 <= nums[i] <= 109
// It is guaranteed that at least one trionic subarray exists.

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        const long long NEG = -4e18;

        vector<long long> inc1(n, NEG), dec(n, NEG), inc2(n, NEG);

        for (int i = 1; i < n; i++) {
            // first increasing (len >= 2)
            if (nums[i] > nums[i-1]) {
                inc1[i] = max((long long)nums[i-1] + nums[i],
                              inc1[i-1] + nums[i]);
            }

            // decreasing (after inc)
            if (nums[i] < nums[i-1]) {
                if (inc1[i-1] != NEG)
                    dec[i] = max(dec[i], inc1[i-1] + nums[i]);
                if (dec[i-1] != NEG)
                    dec[i] = max(dec[i], dec[i-1] + nums[i]);
            }

            // final increasing
            if (nums[i] > nums[i-1]) {
                if (dec[i-1] != NEG)
                    inc2[i] = max(inc2[i], dec[i-1] + nums[i]);
                if (inc2[i-1] != NEG)
                    inc2[i] = max(inc2[i], inc2[i-1] + nums[i]);
            }
        }

        long long ans = NEG;
        for (int i = 0; i < n; i++)
            ans = max(ans, inc2[i]);

        return ans;
    }
};
