/*
给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)
思路：因为多次计算重复区域的和浪费时间，因此将和存在矩阵sum中。

sum[i][j]表示矩形matrix[0][0]到matrix[i][j]的和

优化：判别0很丑，可以考虑给矩阵的左侧和上侧加一行0，这样不需要特判边界。
提交次数：1
2021.3.2
*/
class NumMatrix {
public:
    vector<vector<int>> sum;//0 0到i j的和
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i = 0;i < matrix.size();i++){
            vector<int> tmp;
            for(int j = 0;j < matrix[0].size();j++){
                tmp.push_back(matrix[i][j]);
            }
            sum.push_back(tmp);
        }
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[0].size();j++){
                if(i == 0 && j == 0)
                    sum[i][j] = matrix[i][j];
                else if(i == 0){
                    sum[i][j]  = sum[i][j-1] + matrix[i][j];
                }
                else if(j == 0){
                    sum[i][j]  = sum[i-1][j] + matrix[i][j];
                }
                else
                    sum[i][j]  = sum[i-1][j] + sum[i][j-1] + matrix[i][j] - sum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0)
            return sum[row2][col2];
        if(row1 == 0){
            return sum[row2][col2] - sum[row2][col1-1];
        }
        if(col1 == 0){
            return sum[row2][col2] - sum[row1-1][col2];
        }
        return sum[row2][col2] - sum[row1-1][col2] - sum[row2][col1-1] + sum[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
