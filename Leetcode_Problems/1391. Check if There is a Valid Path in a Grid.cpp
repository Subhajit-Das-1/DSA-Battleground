// You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

// 1 which means a street connecting the left cell and the right cell.
// 2 which means a street connecting the upper cell and the lower cell.
// 3 which means a street connecting the left cell and the lower cell.
// 4 which means a street connecting the right cell and the lower cell.
// 5 which means a street connecting the left cell and the upper cell.
// 6 which means a street connecting the right cell and the upper cell.

// You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

// Notice that you are not allowed to change any street.

// Return true if there is a valid path in the grid or false otherwise.

 

// Example 1:


// Input: grid = [[2,4,3],[6,5,2]]
// Output: true
// Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
// Example 2:


// Input: grid = [[1,2,1],[1,2,1]]
// Output: false
// Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
// Example 3:

// Input: grid = [[1,1,2]]
// Output: false
// Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// 1 <= grid[i][j] <= 6

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Directions: up, down, left, right
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        
        // Map street type → allowed directions
        unordered_map<int, vector<int>> mp = {
            {1, {2, 3}},       // left, right
            {2, {0, 1}},       // up, down
            {3, {2, 1}},       // left, down
            {4, {3, 1}},       // right, down
            {5, {2, 0}},       // left, up
            {6, {3, 0}}        // right, up
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m-1 && c == n-1) return true;

            int type = grid[r][c];

            for (int d : mp[type]) {
                int nr = r + dirs[d][0];
                int nc = c + dirs[d][1];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if (vis[nr][nc]) continue;

                int nextType = grid[nr][nc];

                // Check if next cell connects back
                for (int back : mp[nextType]) {
                    if (nr + dirs[back][0] == r && nc + dirs[back][1] == c) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                        break;
                    }
                }
            }
        }

        return false;
    }
};