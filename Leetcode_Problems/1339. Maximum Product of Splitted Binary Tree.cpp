// Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

// Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

// Note that you need to maximize the answer before taking the mod and not after taking it.

 

// Example 1:


// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
// Example 2:


// Input: root = [1,null,2,3,4,null,null,5,6]
// Output: 90
// Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
 

// Constraints:

// The number of nodes in the tree is in the range [2, 5 * 104].
// 1 <= Node.val <= 104

class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long maxProd = 0;

    // First DFS to compute total sum
    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    // Second DFS to compute subtree sums and max product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subTreeSum = root->val + leftSum + rightSum;

        // Try cutting here
        long long product = subTreeSum * (totalSum - subTreeSum);
        maxProd = max(maxProd, product);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);  // Step 1
        dfs(root);                     // Step 2
        return maxProd % MOD;
    }
};
