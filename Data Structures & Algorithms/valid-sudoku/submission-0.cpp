class Solution {
public:
    bool check(vector<int>& arr){
        for(int k=0; k<9; k++){
            if(arr[k] > 1) return false;
        }
        return true;
    }

    bool checkRow(vector<vector<char>>& board, int i){
        vector<int> row(9, 0);
        for(int j=0; j<9; j++){
            if(board[i][j] != '.'){
                int idx = board[i][j] - '1';
                row[idx]++;
            }
        }
        return check(row);
    }

    bool checkCol(vector<vector<char>>& board, int i){
        vector<int> col(9, 0);
        for(int j=0; j<9; j++){
            if(board[j][i] != '.'){
                int idx = board[j][i] - '1';
                col[idx]++;
            }
        }
        return check(col);
    }

    bool checkBox(vector<vector<char>>& board, int rs, int re, int cs, int ce){
        vector<int> box(9, 0);
        for(int i=rs; i<re; i++){
            for(int j=cs; j<ce; j++){
                if(board[i][j] != '.'){
                    int idx = board[i][j] - '1';
                    box[idx]++;
                }
            }
        }
        return check(box);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            if(!checkRow(board, i) || !checkCol(board, i))
                return false;
        }

        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                if(!checkBox(board, i, i+3, j, j+3))
                    return false;
            }
        }

        return true;
    }
};
