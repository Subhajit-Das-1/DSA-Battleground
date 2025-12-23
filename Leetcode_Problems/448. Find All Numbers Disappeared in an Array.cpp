// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]
// Example 2:

// Input: nums = [1,1]
// Output: [2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // [3,2,3,4,8,2,7,1]
        int n = nums.size();
        int i = 0;

        while(i < n){
            int correctIdx = nums[i] - 1;
            if(nums[correctIdx] == nums[i] || correctIdx == i) i++;
            else swap(nums[i], nums[correctIdx]);
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1) ans.push_back(i + 1);
        }

        return ans;
    }
};
