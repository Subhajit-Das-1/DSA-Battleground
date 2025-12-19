// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        if(n==2){
            if(target==nums[0]) return 0;
            else if(target==nums[1]) return 1;
            else return -1;
        }

        int lo = 0;
        int hi = n - 1;
        int pivot = -1;

        // -------- FIXED pivot loop --------
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // check pivot normally
            if (nums[mid] <= nums[(mid + 1) % n] && nums[mid] < nums[(mid - 1 + n) % n]) {
                pivot = mid;
                break;
            }
            else if (nums[mid] >= nums[0])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        // ----------------------------------

        // If pivot not found → array not rotated → binary search whole array
        if(pivot == -1){
            lo = 0;
            hi = n - 1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) hi = mid - 1;
                else lo = mid + 1;
            }
            return -1;
        }

        // Search in left half
        if (target >= nums[0] && target <= nums[pivot - 1]) {
            lo = 0;
            hi = pivot - 1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) hi = mid - 1;
                else lo = mid + 1;
            }
        }
        // Search in right half
        else {
            lo = pivot;
            hi = n - 1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) hi = mid - 1;
                else lo = mid + 1;
            }
        }

        return -1;
    }
};
