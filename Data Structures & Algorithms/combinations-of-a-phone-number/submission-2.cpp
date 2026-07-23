class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> ans;
    string curr;

    void backtrack(string &digits, int idx) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        for (char ch : mp[digits[idx]]) {
            curr.push_back(ch);
            backtrack(digits, idx + 1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        backtrack(digits, 0);
        return ans;
    }
};
