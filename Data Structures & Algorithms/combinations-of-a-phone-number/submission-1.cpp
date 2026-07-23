class Solution {
public:
    unordered_map<int, string> mp = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

    vector<string> res;

    void helper(string &digits, string curr, int i) {
        if (i == digits.size()) {
            res.push_back(curr);
            return;
        }

        for (char ch : mp[digits[i] - '0']) {
            helper(digits, curr + ch, i + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        helper(digits, "", 0);
        return res;
    }
};
