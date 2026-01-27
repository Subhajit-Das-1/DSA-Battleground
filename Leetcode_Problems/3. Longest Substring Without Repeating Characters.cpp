// Given a string s, find the length of the longest substring without duplicate characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1); // store last index of each character
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // if character already seen and inside window
            if (last[c] >= left) {
                left = last[c] + 1;
            }

            last[c] = right;                 // update last seen index
            ans = max(ans, right - left + 1); // update answer
        }

        return ans;
    }
};
