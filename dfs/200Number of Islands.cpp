/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

思路：求无向图连通分量的数目，常用方法DFS、并查集
注：并查集还未实现

2021.3.1
提交次数：1
*/
class Solution {
public:
    //连通分量的数目：DFS或者并查集
    
    //dfs把1相连的1都变成0
    void dfs(vector<vector<char>>& grid,int row, int col){
        grid[row][col] = '0';

        //cout << row << " " << col << endl;
        int m = grid.size();
        int n = grid[0].size();
        if(row-1 >= 0 && grid[row-1][col] == '1') 
            dfs(grid,row-1,col);
        if(col-1 >= 0 && grid[row][col-1] == '1') 
            dfs(grid,row,col-1);
        if(row+1 < m && grid[row+1][col] == '1') 
            dfs(grid,row+1,col);
        if(col+1 < n && grid[row][col+1] == '1') 
            dfs(grid,row,col+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int sum = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    sum++;
                }
            }
        }
        return sum;
    }
};
