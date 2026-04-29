/*
 * 题目：最长公共前缀 (Longest Common Prefix)
 * 难度：Easy
 * 标签：字符串，数组
 * 
 * 题目描述：
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 解题思路：
 * 1. 以第一个字符串为基准
 * 2. 逐字符与其他字符串的对应位置比较
 * 3. 如果所有字符串在该位置的字符都相同，加入结果
 * 4. 遇到不同字符或某个字符串结束，返回当前结果
 * 5. 时间复杂度：O(S)，S 为所有字符串的字符总数
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 函数功能：查找字符串数组的最长公共前缀
 * 参数：
 *   - strs: 字符串数组
 * 返回值：最长公共前缀字符串
 */
string longestCommonPrefix(vector<string>& strs) {
    // 边界情况：空数组
    if (strs.empty()) {
        return "";
    }
    
    // 边界情况：只有一个字符串
    if (strs.size() == 1) {
        return strs[0];
    }
    
    // 遍历第一个字符串的每个字符
    for (int i = 0; i < strs[0].size(); i++) {
        char currentChar = strs[0][i];
        
        // 检查其他字符串在位置 i 的字符
        for (int j = 1; j < strs.size(); j++) {
            // 如果某个字符串已经结束，或字符不匹配
            if (i >= strs[j].size() || strs[j][i] != currentChar) {
                // 返回第一个字符串的前 i 个字符
                return strs[0].substr(0, i);
            }
        }
    }
    
    // 第一个字符串本身就是公共前缀
    return strs[0];
}

int main() {
    // 加速输入输出流
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    // 读取字符串数量
    cin >> n;
    
    vector<string> strs(n);
    // 读取所有字符串
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    // 调用函数求解
    string result = longestCommonPrefix(strs);
    
    // 输出结果
    cout << result << endl;
    
    return 0;
}

/*
 * 测试样例 1：
 * 输入：
 * 3
 * flower flow flight
 * 
 * 输出：
 * fl
 * 
 * 测试样例 2：
 * 输入：
 * 3
 * dog racecar car
 * 
 * 输出：
 * (空字符串)
 */
