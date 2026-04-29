/*
 * 题目：最大子数组和 (Maximum Subarray)
 * 难度：Medium
 * 标签：数组，动态规划，分治
 * 
 * 题目描述：
 * 给定一个整数数组 nums，找出一个具有最大和的连续子数组，
 * 返回其最大和。
 * 
 * 解题思路（动态规划 - Kadane 算法）：
 * 1. 定义状态：dp[i] 表示以第 i 个元素结尾的最大子数组和
 * 2. 状态转移：dp[i] = max(nums[i], dp[i-1] + nums[i])
 *    - 要么从当前元素重新开始
 *    - 要么将当前元素加入之前的子数组
 * 3. 优化：只需要一个变量记录前一个状态，空间复杂度降为 O(1)
 * 4. 时间复杂度：O(n)，空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 函数功能：计算最大子数组和
 * 参数：
 *   - nums: 整数数组
 * 返回值：最大连续子数组的和
 */
int maxSubArray(vector<int>& nums) {
    // 初始化：当前连续和、最大和
    int currentSum = nums[0];
    int maxSum = nums[0];
    
    // 从第二个元素开始遍历
    for (size_t i = 1; i < nums.size(); i++) {
        // 核心决策：
        // 1. 将当前元素加入之前的子数组
        // 2. 从当前元素重新开始新的子数组
        // 取两者中的较大值
        currentSum = max(nums[i], currentSum + nums[i]);
        
        // 更新全局最大值
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

int main() {
    // 加速输入输出流
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    // 读取数组大小
    cin >> n;
    
    vector<int> nums(n);
    // 读取数组元素
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // 调用函数求解
    int result = maxSubArray(nums);
    
    // 输出结果
    cout << result << endl;
    
    return 0;
}

/*
 * 测试样例：
 * 输入：
 * 9
 * -2 1 -3 4 -1 2 1 -5 4
 * 
 * 输出：
 * 6
 * 
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6
 */
