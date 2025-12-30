// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

// Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

// Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

// Example 1:


// Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
// Output: 1
// Explanation: 
// The following subgrid is a 3 x 3 magic square:

// while this one is not:

// In total, there is only one magic square inside the given grid.
// Example 2:

// Input: grid = [[8]]
// Output: 0
 

// Constraints:

// row == grid.length
// col == grid[i].length
// 1 <= row, col <= 10
// 0 <= grid[i][j] <= 15

class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        // Center must be 5
        if (grid[r+1][c+1] != 5) return false;

        vector<bool> seen(10, false);

        // Check numbers 1 to 9 and uniqueness
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || seen[val]) return false;
                seen[val] = true;
            }
        }

        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

        // Rows
        for (int i = 0; i < 3; i++) {
            if (grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != sum)
                return false;
        }

        // Columns
        for (int j = 0; j < 3; j++) {
            if (grid[r][c+j] + grid[r+1][c+j] + grid[r+2][c+j] != sum)
                return false;
        }

        // Diagonals
        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum)
            return false;
        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};
