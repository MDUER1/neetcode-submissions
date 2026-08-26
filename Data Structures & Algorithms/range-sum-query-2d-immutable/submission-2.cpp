class NumMatrix {
private:
    vector<vector<int>> sumMat; // matrix where each cell will store the sums for sumRegion() to use

public:
    NumMatrix(vector<vector<int>>& matrix) { // We are gonna do preprocessing
        int rows{static_cast<int>(matrix.size())};
        int cols{static_cast<int>(matrix[0].size())};
        // Create an vector that contains cols + 1 ints initialized to 0
        // Create rows + 1 copies of that inner vector. The +1 is a zero-border
        sumMat = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        for (int r = 0; r < rows; r++) {
            int prefix = 0; // For every new row
            for (int c = 0; c < cols; c++) {
                prefix += matrix[r][c];
                int above = sumMat[r][c + 1]; // cell directly above [r + 1][ c + 1]
                sumMat[r + 1][c + 1] = prefix + above; // vertical and horizontal sum to get square
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++; //Converts the SumMat coordinates to matrix coordinates
        int bottomRight = sumMat[row2][col2];
        int above = sumMat[row1 - 1][col2];
        int left = sumMat[row2][col1 - 1];
        int topLeft = sumMat[row1 - 1][col1 - 1];
        return bottomRight - above - left + topLeft;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */