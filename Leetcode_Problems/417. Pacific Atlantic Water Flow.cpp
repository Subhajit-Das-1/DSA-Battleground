// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

// The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 

// Example 1:


// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
// [0,4]: [0,4] -> Pacific Ocean 
//        [0,4] -> Atlantic Ocean
// [1,3]: [1,3] -> [0,3] -> Pacific Ocean 
//        [1,3] -> [1,4] -> Atlantic Ocean
// [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
//        [1,4] -> Atlantic Ocean
// [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
//        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
// [3,0]: [3,0] -> Pacific Ocean 
//        [3,0] -> [4,0] -> Atlantic Ocean
// [3,1]: [3,1] -> [3,0] -> Pacific Ocean 
//        [3,1] -> [4,1] -> Atlantic Ocean
// [4,0]: [4,0] -> Pacific Ocean 
//        [4,0] -> Atlantic Ocean
// Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
// Example 2:

// Input: heights = [[1]]
// Output: [[0,0]]
// Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
 

// Constraints:

// m == heights.length
// n == heights[r].length
// 1 <= m, n <= 200
// 0 <= heights[r][c] <= 105

class Solution {      // BFS Solution (Iterative, Optimized)
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int,int>> qp, qa;
        vector<pair<int,int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};

        // Pacific: top row + left column
        for (int c = 0; c < n; c++) {
            qp.push({0, c});
            pacific[0][c] = true;
        }
        for (int r = 0; r < m; r++) {
            qp.push({r, 0});
            pacific[r][0] = true;
        }

        // Atlantic: bottom row + right column
        for (int c = 0; c < n; c++) {
            qa.push({m - 1, c});
            atlantic[m - 1][c] = true;
        }
        for (int r = 0; r < m; r++) {
            qa.push({r, n - 1});
            atlantic[r][n - 1] = true;
        }

        // BFS function (inline)
        auto bfs = [&](queue<pair<int,int>>& q, vector<vector<bool>>& visited) {
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& d : dirs) {
                    int nr = r + d.first;
                    int nc = c + d.second;

                    if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                    if (visited[nr][nc]) continue;
                    if (heights[nr][nc] < heights[r][c]) continue;

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        };

        bfs(qp, pacific);
        bfs(qa, atlantic);

        vector<vector<int>> result;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
  
class Solution {  // DFS Solution (Recursive)
public:
    int m, n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[r][c] = true;

        for (auto& d : directions) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (visited[nr][nc]) continue;
            if (heights[nr][nc] < heights[r][c]) continue;

            dfs(nr, nc, heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific: top row + left column
        for (int c = 0; c < n; c++)
            dfs(0, c, heights, pacific);
        for (int r = 0; r < m; r++)
            dfs(r, 0, heights, pacific);

        // Atlantic: bottom row + right column
        for (int c = 0; c < n; c++)
            dfs(m - 1, c, heights, atlantic);
        for (int r = 0; r < m; r++)
            dfs(r, n - 1, heights, atlantic);

        vector<vector<int>> result;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
