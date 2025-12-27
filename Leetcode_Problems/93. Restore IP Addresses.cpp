// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 

// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
// Example 2:

// Input: s = "0000"
// Output: ["0.0.0.0"]
// Example 3:

// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

// Constraints:

// 1 <= s.length <= 20
// s consists of digits only.

class Solution {
public:
    vector<string> result;

    void backtrack(string& s, int index, int parts, string current) {
        // If 4 parts used
        if (parts == 4) {
            if (index == s.length()) {
                result.push_back(current.substr(0, current.size() - 1));
            }
            return;
        }

        // Try segments of length 1 to 3
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.length()) break;

            string part = s.substr(index, len);

            // Leading zero check
            if (part.size() > 1 && part[0] == '0') continue;

            int value = stoi(part);
            if (value > 255) continue;

            backtrack(s, index + len, parts + 1, current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return result;
    }
};
