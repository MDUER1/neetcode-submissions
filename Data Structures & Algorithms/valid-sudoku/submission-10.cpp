class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> seen;
        int rows{static_cast<int>(board.size())};
        int cols{static_cast<int>(board[0].size())};

        // Check each row for dups        
        for (int r{}; r < rows; ++r) {
            seen.clear();
            for (int c{}; c < cols; ++c) {
                if (board[r][c] != '.' && seen.contains(board[r][c])) {
                    return false;
                }
                
                seen.insert(board[r][c]);
            }
        }

        // Check each col for dups
        for (int c{}; c < cols; ++c) {
            seen.clear();
            for (int r{}; r < rows; ++r) {
                if (board[r][c] != '.' && seen.contains(board[r][c])) {
                    return false;
                }

                seen.insert(board[r][c]);
            }
        }
        seen.clear();
        //Check the sub box
            int stopCol{3};
            int stopRow{3};
            int startCol{0};
            int startRow{0};
        while(true) {
            for(int r{startRow}; r < stopRow; ++r) {
                for (int c{startCol}; c < stopCol; ++c) {
                    if (board[r][c] != '.' && seen.contains(board[r][c])) {
                        return false;
                    }
                seen.insert(board[r][c]);
                }
            }
            
            seen.clear();
            if (stopCol < 9) {
                stopCol += 3;
                startCol +=3;
            } else {
                stopCol = 3;
                startCol = 0;
                startRow += 3;
                stopRow += 3;
            }

            if (stopRow > 9) {
                break;
            }
        }
     return true;

    }
};
