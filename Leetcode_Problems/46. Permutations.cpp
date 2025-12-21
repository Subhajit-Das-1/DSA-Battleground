// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique

class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used;

    void backtrack(vector<int>& nums) {
        // Base case: one permutation completed
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        // Try each number
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;   // skip already used numbers

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Explore
            backtrack(nums);

            // Unchoose (backtrack)
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);
        backtrack(nums);
        return result;
    }
};
