// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

// Example 1:


// Input: n = 3
// Output: 5
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 19

class Solution { // Catalan Number
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        
        dp[0] = 1;  // empty tree
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        return dp[n];
    }
};

class Solution { // Catalan Number - Direct Formula
public:
    int numTrees(int n) {
        long long res = 1;
        
        for (int i = 0; i < n; i++) {
            res = res * (2 * n - i) / (i + 1);
        }
        
        return res / (n + 1);
    }
};