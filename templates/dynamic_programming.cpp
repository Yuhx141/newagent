/*
 * 动态规划 (DP) 常用模板集合
 * 
 * 包含：
 * 1. 斐波那契数列（入门 DP）
 * 2. 0-1 背包问题
 * 3. 完全背包问题
 * 4. 最长递增子序列 (LIS)
 * 5. 最长公共子序列 (LCS)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==================== 1. 斐波那契数列 ====================
/**
 * 计算斐波那契数列第 n 项
 * 时间复杂度：O(n)，空间复杂度：O(1)
 */
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    
    int prev2 = 0;  // f(n-2)
    int prev1 = 1;  // f(n-1)
    int current;
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

// ==================== 2. 0-1 背包问题 ====================
/**
 * 0-1 背包问题
 * 参数：
 *   - weights: 物品重量数组
 *   - values: 物品价值数组
 *   - capacity: 背包容量
 * 返回值：能获得的最大价值
 * 
 * 状态转移方程：
 * dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i])
 */
int knapsack01(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            // 不选第 i 个物品
            dp[i][j] = dp[i - 1][j];
            
            // 选第 i 个物品（如果容量允许）
            if (j >= weights[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    
    return dp[n][capacity];
}

// 空间优化版本
int knapsack01Optimized(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < n; i++) {
        // 必须从后往前遍历，避免重复使用同一物品
        for (int j = capacity; j >= weights[i]; j--) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    
    return dp[capacity];
}

// ==================== 3. 完全背包问题 ====================
/**
 * 完全背包问题（每个物品可以选无限次）
 * 参数：
 *   - weights: 物品重量数组
 *   - values: 物品价值数组
 *   - capacity: 背包容量
 * 返回值：能获得的最大价值
 * 
 * 与 0-1 背包的区别：内层循环从前往后遍历
 */
int unboundedKnapsack(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < n; i++) {
        // 从前往后遍历，允许重复使用同一物品
        for (int j = weights[i]; j <= capacity; j++) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    
    return dp[capacity];
}

// ==================== 4. 最长递增子序列 (LIS) ====================
/**
 * 最长递增子序列
 * 参数：
 *   - nums: 整数数组
 * 返回值：LIS 的长度
 * 
 * 状态转移方程：
 * dp[i] = max(dp[j] + 1)，其中 j < i 且 nums[j] < nums[i]
 */
int lengthOfLIS(const vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    
    int n = nums.size();
    vector<int> dp(n, 1);  // 每个元素本身构成长度为 1 的 LIS
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

// ==================== 5. 最长公共子序列 (LCS) ====================
/**
 * 最长公共子序列
 * 参数：
 *   - text1: 第一个字符串
 *   - text2: 第二个字符串
 * 返回值：LCS 的长度
 * 
 * 状态转移方程：
 * 如果 s1[i] == s2[j]: dp[i][j] = dp[i-1][j-1] + 1
 * 否则：dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 */
int longestCommonSubsequence(const string& text1, const string& text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cout << "=== 斐波那契数列 ===" << endl;
    int n;
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    
    cout << "\n=== 0-1 背包问题 ===" << endl;
    int capacity, itemNum;
    cin >> capacity >> itemNum;
    vector<int> weights(itemNum), values(itemNum);
    for (int i = 0; i < itemNum; i++) {
        cin >> weights[i] >> values[i];
    }
    cout << "最大价值：" << knapsack01Optimized(weights, values, capacity) << endl;
    
    cout << "\n=== 最长递增子序列 ===" << endl;
    int len;
    cin >> len;
    vector<int> nums(len);
    for (int i = 0; i < len; i++) {
        cin >> nums[i];
    }
    cout << "LIS 长度：" << lengthOfLIS(nums) << endl;
    
    cout << "\n=== 最长公共子序列 ===" << endl;
    string s1, s2;
    cin >> s1 >> s2;
    cout << "LCS 长度：" << longestCommonSubsequence(s1, s2) << endl;
    
    return 0;
}

/*
 * 测试样例：
 * 斐波那契：输入 10，输出 55
 * 
 * 0-1 背包：
 * 输入：
 * 10 3
 * 2 3
 * 3 4
 * 4 5
 * 输出：最大价值 13
 * 
 * LIS：
 * 输入：
 * 6
 * 10 9 2 5 3 7
 * 输出：LIS 长度 3（[2,3,7] 或 [2,5,7]）
 * 
 * LCS：
 * 输入：
 * abcde ace
 * 输出：LCS 长度 3（"ace"）
 */
