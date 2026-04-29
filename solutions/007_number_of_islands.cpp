/*
 * 题目：岛屿数量 (Number of Islands)
 * 难度：Medium
 * 标签：图论，DFS，BFS，并查集
 * 
 * 题目描述：
 * 给你一个由 '1'（陆地）和 '0'（水域）组成的二维网格，
 * 计算网格中岛屿的数量。
 * 岛屿总是被水包围，并且每座岛屿只能由水平或垂直方向
 * 相邻的陆地连接形成。
 * 
 * 解题思路（DFS）：
 * 1. 遍历整个网格
 * 2. 遇到 '1' 时，岛屿数 +1，然后使用 DFS 将整个岛屿的 '1' 都标记为 '0'
 * 3. DFS 会递归访问上下左右四个方向的相邻陆地
 * 4. 时间复杂度：O(m*n)，空间复杂度：O(m*n)（递归栈空间）
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * DFS 辅助函数：淹没整个岛屿
 * 参数：
 *   - grid: 网格
 *   - row, col: 当前位置
 */
void dfs(vector<vector<char>>& grid, int row, int col) {
    // 边界检查
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
        return;
    }
    
    // 如果是水域，直接返回
    if (grid[row][col] == '0') {
        return;
    }
    
    // 将当前陆地标记为水域（避免重复访问）
    grid[row][col] = '0';
    
    // 递归访问四个方向：上、下、左、右
    dfs(grid, row - 1, col);  // 上
    dfs(grid, row + 1, col);  // 下
    dfs(grid, row, col - 1);  // 左
    dfs(grid, row, col + 1);  // 右
}

/**
 * 函数功能：计算岛屿数量
 * 参数：
 *   - grid: 由 '1' 和 '0' 组成的二维网格
 * 返回值：岛屿的数量
 */
int numIslands(vector<vector<char>>& grid) {
    // 边界情况：空网格
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }
    
    int islandCount = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    
    // 遍历整个网格
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // 发现新岛屿
            if (grid[i][j] == '1') {
                islandCount++;
                // 使用 DFS 淹没整个岛屿
                dfs(grid, i, j);
            }
        }
    }
    
    return islandCount;
}

int main() {
    // 加速输入输出流
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    // 读取网格的行数和列数
    cin >> m >> n;
    
    vector<vector<char>> grid(m, vector<char>(n));
    // 读取网格
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    // 调用函数求解
    int result = numIslands(grid);
    
    // 输出结果
    cout << result << endl;
    
    return 0;
}

/*
 * 测试样例 1：
 * 输入：
 * 4 5
 * 1 1 1 1 0
 * 1 1 0 1 0
 * 1 1 0 0 0
 * 0 0 0 0 0
 * 
 * 输出：
 * 1
 * 
 * 测试样例 2：
 * 输入：
 * 4 5
 * 1 1 0 0 0
 * 1 1 0 0 0
 * 0 0 1 0 0
 * 0 0 0 1 1
 * 
 * 输出：
 * 3
 */
