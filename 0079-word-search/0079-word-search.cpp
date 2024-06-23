class Solution {
public:
    bool backtrack(int i, int j, int indx, vector<vector<char>>& board, string word, int m, int n) {
        if (indx == word.length()) {
            return true;
        }
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[indx]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '\0';

        if (backtrack(i + 1, j, indx + 1, board, word, m, n) || backtrack(i - 1, j, indx + 1, board, word, m, n) ||
            backtrack(i, j + 1, indx + 1, board, word, m, n) || backtrack(i, j - 1, indx + 1, board, word, m, n)) {
            return true;
        }

        board[i][j] = temp;
        return false;
    };

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(i, j, 0, board, word, m, n)) {
                    return true;
                }
            }
        }
        return false;
    }
};