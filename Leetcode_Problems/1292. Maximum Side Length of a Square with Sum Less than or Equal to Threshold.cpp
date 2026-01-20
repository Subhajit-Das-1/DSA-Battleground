// Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

 

// Example 1:


// Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
// Output: 2
// Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
// Example 2:

// Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
// Output: 0
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 300
// 0 <= mat[i][j] <= 104
// 0 <= threshold <= 105

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        
        // 1. Build prefix sum matrix
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = mat[i - 1][j - 1]
                          + pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1];
            }
        }
        
        // Helper function to check if square of size k exists
        auto can = [&](int k) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int sum = pre[i + k][j + k]
                            - pre[i][j + k]
                            - pre[i + k][j]
                            + pre[i][j];
                    if (sum <= threshold) return true;
                }
            }
            return false;
        };
        
        // 2. Binary search on side length
        int low = 0, high = min(m, n), ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
