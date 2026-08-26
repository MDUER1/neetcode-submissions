class NumMatrix {
private:
    vector<vector<int>> sumMatrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows{static_cast<int>(matrix.size())};
        int cols{static_cast<int>(matrix[0].size())};
        sumMatrix = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        for (int r{}; r < rows; r++) {
            int prefix{};
            for (int c{}; c < cols; c++) {
                prefix += matrix[r][c];
                int above = sumMatrix[r][c + 1];
                sumMatrix[r + 1][c + 1] = above + prefix;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        ++row1;
        ++col1;
        ++row2;
        ++col2;

        int bottomRight = sumMatrix[row2][col2];
        int above = sumMatrix[row1 - 1][col2];
        int left = sumMatrix[row2][col1 - 1];
        int topLeft = sumMatrix[row1 - 1][col1 - 1];
        return bottomRight - above - left + topLeft;
    }
};


