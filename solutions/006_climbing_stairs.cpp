/*
 * 题目：爬楼梯 (Climbing Stairs)
 * 难度：Easy
 * 标签：动态规划，递推，记忆化搜索
 * 
 * 题目描述：
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶？
 * 
 * 解题思路（动态规划）：
 * 1. 状态定义：dp[i] 表示爬到第 i 阶的方法数
 * 2. 状态转移方程：dp[i] = dp[i-1] + dp[i-2]
 *    - 从第 i-1 阶爬 1 步到达
 *    - 从第 i-2 阶爬 2 步到达
 * 3. 初始状态：dp[0] = 1, dp[1] = 1
 * 4. 优化：只需要两个变量记录前两个状态
 * 5. 时间复杂度：O(n)，空间复杂度：O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 函数功能：计算爬楼梯的方法数
 * 参数：
 *   - n: 楼梯的总阶数
 * 返回值：到达楼顶的不同方法数
 */
int climbStairs(int n) {
    // 边界情况
    if (n <= 1) {
        return 1;
    }
    
    // 只需要记录前两个状态，节省空间
    int prev2 = 1;  // dp[i-2]，初始为 dp[0]
    int prev1 = 1;  // dp[i-1]，初始为 dp[1]
    int current;    // dp[i]
    
    // 从第 2 阶开始计算
    for (int i = 2; i <= n; i++) {
        // 状态转移：当前阶的方法数 = 前一阶 + 前两阶的方法数
        current = prev1 + prev2;
        
        // 更新状态，为下一次迭代做准备
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

int main() {
    // 加速输入输出流
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    // 读取楼梯阶数
    cin >> n;
    
    // 调用函数求解
    int result = climbStairs(n);
    
    // 输出结果
    cout << result << endl;
    
    return 0;
}

/*
 * 测试样例 1：
 * 输入：
 * 2
 * 
 * 输出：
 * 2
 * 解释：有两种方法可以爬到楼顶
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 * 
 * 测试样例 2：
 * 输入：
 * 3
 * 
 * 输出：
 * 3
 * 解释：有三种方法可以爬到楼顶
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 */
