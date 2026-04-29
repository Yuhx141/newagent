/*
 * 题目：二分查找 (Binary Search)
 * 难度：Easy
 * 标签：数组，二分查找，分治
 * 
 * 题目描述：
 * 给定一个升序排列的整数数组 nums 和一个目标值 target，
 * 在数组中查找目标值，如果存在返回下标，否则返回 -1。
 * 
 * 解题思路：
 * 1. 使用双指针，left 指向数组开始，right 指向数组末尾
 * 2. 计算中间位置 mid，比较 nums[mid] 与 target
 * 3. 如果 nums[mid] == target，找到目标
 * 4. 如果 nums[mid] < target，目标在右半部分，left = mid + 1
 * 5. 如果 nums[mid] > target，目标在左半部分，right = mid - 1
 * 6. 时间复杂度：O(log n)，空间复杂度：O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 函数功能：在有序数组中二分查找目标值
 * 参数：
 *   - nums: 升序排列的整数数组
 *   - target: 要查找的目标值
 * 返回值：目标值的索引，不存在则返回 -1
 */
int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    // 当搜索区间不为空时继续
    while (left <= right) {
        // 计算中间位置，防止溢出的写法
        int mid = left + (right - left) / 2;
        
        // 找到目标值
        if (nums[mid] == target) {
            return mid;
        }
        // 目标值在右半部分
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        // 目标值在左半部分
        else {
            right = mid - 1;
        }
    }
    
    // 未找到目标值
    return -1;
}

int main() {
    // 加速输入输出流
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, target;
    // 读取数组大小和目标值
    cin >> n >> target;
    
    vector<int> nums(n);
    // 读取有序数组
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // 调用函数查找
    int result = binarySearch(nums, target);
    
    // 输出结果
    cout << result << endl;
    
    return 0;
}

/*
 * 测试样例 1：
 * 输入：
 * 5 3
 * 1 2 3 4 5
 * 
 * 输出：
 * 2
 * 
 * 测试样例 2：
 * 输入：
 * 5 6
 * 1 2 3 4 5
 * 
 * 输出：
 * -1
 */
