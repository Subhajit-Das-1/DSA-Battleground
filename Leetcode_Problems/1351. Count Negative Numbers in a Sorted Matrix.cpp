// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

// Example 1:

// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.
// Example 2:

// Input: grid = [[3,2],[1,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// -100 <= grid[i][j] <= 100

class Solution {      // method 1 : Binary Search
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            int low = 0, high = n - 1;
            int firstNeg = n;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (grid[i][mid] < 0) {
                    firstNeg = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            count += (n - firstNeg);
        }

        return count;
    }
};

 class Solution {  // method 2 : Staircase Search
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int row = 0;
        int col = n - 1;
        int count = 0;
        
        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                count += (m - row); // all below are negative
                col--;              // move left
            } else {
                row++;              // move down
            }
        }
        
        return count;
    }
};