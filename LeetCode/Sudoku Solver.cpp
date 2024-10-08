class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isVaild(board, i, j, k)) {
                            board[i][j] =  k;

                            if (solve(board)) {
                                return true;
                            }
                            else {
                                board[i][j] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    bool isVaild(vector<vector<char>>& board, int i, int j, char k) {
        for (int idx = 0; idx < 9; idx++){
            if (board[idx][j] == k) return false;
            if (board[i][idx] == k) return false;
            if (board[(i / 3) * 3 + idx / 3][(j / 3) * 3 + idx % 3] == k) return false;
        }

        return true;
    }
};