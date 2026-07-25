class Solution {
public:
    vector<vector<pair<int,int>>> res;

    bool check(int r, int c, vector<pair<int,int>>& curr) {
        for (auto &[pr, pc] : curr) {
            if (pc == c) return false;                      
            if (abs(pr - r) == abs(pc - c)) return false;  
        }
        return true;
    }

    void helper(vector<pair<int,int>>& curr, int n, int r) {

        if (r == n) {
            res.push_back(curr);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (check(r, c, curr)) {
                curr.push_back({r, c});
                helper(curr, n, r + 1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<pair<int,int>> curr;
        helper(curr, n, 0);

        vector<vector<string>> ans;

        for (auto &v : res) {
            vector<string> temp(n, string(n, '.'));

            for (auto &[r, c] : v)
                temp[r][c] = 'Q';

            ans.push_back(temp);
        }

        return ans;
    }
};