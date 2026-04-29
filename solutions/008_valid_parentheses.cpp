/*
 * 题目：有效的括号 (Valid Parentheses)
 * 难度：Easy
 * 标签：栈，字符串
 * 
 * 题目描述：
 * 给定一个只包括 '(', ')', '{', '}', '[', ']' 的字符串 s，
 * 判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 1. 左括号必须用相同类型的右括号闭合。
 * 2. 左括号必须以正确的顺序闭合。
 * 3. 每个右括号都有一个对应的相同类型的左括号。
 * 
 * 解题思路（栈）：
 * 1. 使用栈存储左括号
 * 2. 遇到左括号，压入栈
 * 3. 遇到右括号，检查栈顶是否为对应的左括号
 * 4. 如果匹配，弹出栈顶；否则返回 false
 * 5. 最后检查栈是否为空
 * 6. 时间复杂度：O(n)，空间复杂度：O(n)
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/**
 * 函数功能：判断括号字符串是否有效
 * 参数：
 *   - s: 括号字符串
 * 返回值：true 表示有效，false 表示无效
 */
bool isValid(string s) {
    // 边界情况：空字符串有效
    if (s.empty()) {
        return true;
    }
    
    // 奇数长度的字符串一定无效
    if (s.size() % 2 != 0) {
        return false;
    }
    
    // 使用栈存储左括号
    stack<char> stk;
    
    // 遍历字符串
    for (char c : s) {
        // 左括号，压入栈
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        }
        // 右括号，检查匹配
        else {
            // 栈为空说明没有对应的左括号
            if (stk.empty()) {
                return false;
            }
            
            char top = stk.top();
            stk.pop();
            
            // 检查括号类型是否匹配
            if (c == ')' && top != '(') {
                return false;
            }
            if (c == '}' && top != '{') {
                return false;
            }
            if (c == ']' && top != '[') {
                return false;
            }
        }
    }
    
    // 栈为空说明所有括号都正确匹配
    return stk.empty();
}

int main() {
    // 加速输入输出流
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    // 读取括号字符串
    cin >> s;
    
    // 调用函数判断
    bool result = isValid(s);
    
    // 输出结果
    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}

/*
 * 测试样例 1：
 * 输入：
 * ()
 * 
 * 输出：
 * true
 * 
 * 测试样例 2：
 * 输入：
 * ()[]{}
 * 
 * 输出：
 * true
 * 
 * 测试样例 3：
 * 输入：
 * (]
 * 
 * 输出：
 * false
 * 
 * 测试样例 4：
 * 输入：
 * ([)]
 * 
 * 输出：
 * false
 */
