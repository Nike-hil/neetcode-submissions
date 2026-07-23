class Solution {
public:
    vector<string> res;
    void helper(int op,int cl, string curr,int n){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }
        if(op<n){
            helper(op+1,cl,curr+'(',n);
        }
        if(cl<op){
            helper(op,cl+1,curr+')',n);
        }
    }
    vector<string> generateParenthesis(int n) {
        helper(0,0,"",n);
        return res;
    }
};
