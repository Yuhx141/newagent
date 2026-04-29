/*
 * 题目：两数之和 (Two Sum)
 * 难度：Easy
 * 标签：数组，哈希表
 * 
 * 题目描述：
 * 给定一个整数数组 nums 和一个整数目标值 target，
 * 找出数组中和为目标值的两个整数，返回它们的数组下标。
 * 
 * 解题思路：
 * 1. 使用哈希表存储已遍历的数字及其索引
 * 2. 对于每个数字，计算其补数（target - 当前数字）
 * 3. 如果补数存在于哈希表中，说明找到了答案
 * 4. 时间复杂度：O(n)，空间复杂度：O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 函数功能：在数组中找到两个数，使它们的和等于目标值
 * 参数：
 *   - nums: 整数数组
 *   - target: 目标和
 * 返回值：包含两个索引的向量
 */
vector<int> twoSum(vector<int>& nums, int target) {
    // 哈希表：存储数字值 -> 索引的映射
    unordered_map<int, int> numMap;
    
    // 遍历数组
    for (int i = 0; i < nums.size(); i++) {
        // 计算需要找到的补数
        int complement = target - nums[i];
        
        // 如果补数已在哈希表中，找到答案
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        
        // 将当前数字及其索引存入哈希表
        numMap[nums[i]] = i;
    }
    
    // 无解情况（题目保证有解，这里只是防御性编程）
    return {};
}

int main() {
    // 加速输入输出流
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, target;
    // 读取数组大小和目标值
    cin >> n >> target;
    
    vector<int> nums(n);
    // 读取数组元素
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // 调用函数求解
    vector<int> result = twoSum(nums, target);
    
    // 输出结果
    cout << result[0] << " " << result[1] << endl;
    
    return 0;
}

/*
 * 测试样例：
 * 输入：
 * 4 9
 * 2 7 11 15
 * 
 * 输出：
 * 0 1
 * 
 * 解释：nums[0] + nums[1] = 2 + 7 = 9
 */
