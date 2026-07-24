class Solution {
public:
    bool dfs(int i,int j,int k,vector<vector<char>>& board,string word){
        int r=board.size();
        int c=board[0].size();
        if(i<0||j<0||i>=r||j>=c) return false;

        if(word[k]!=board[i][j]) return false;

        if(k==word.size()-1) return true;

        char temp= board[i][j];
        board[i][j]='#';

        bool found=dfs(i-1,j,k+1,board,word)||dfs(i,j-1,k+1,board,word)||dfs(i,j+1,k+1,board,word)||dfs(i+1,j,k+1,board,word);
        
        board[i][j]=temp;
        
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i,j,0,board,word))
                    return true;
            }
        }

        return false;        
    }
};
