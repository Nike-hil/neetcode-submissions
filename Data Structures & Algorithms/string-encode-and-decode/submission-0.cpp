class Solution {
public:

    string encode(vector<string>& strs) {
    string s;
    for (auto& str : strs) {
        s += to_string(str.size()) + "#" + str;
    }
    return s;
    }
    vector<string> decode(string s) {
        vector<string> strs;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#') j++;
            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, len);
            strs.push_back(word);
            i = j + 1 + len;
        }
        return strs;

    }
};
