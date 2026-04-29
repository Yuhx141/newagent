/*
 * 题目：合并两个有序链表 (Merge Two Sorted Lists)
 * 难度：Easy
 * 标签：链表，双指针，归并
 * 
 * 题目描述：
 * 将两个升序链表合并为一个新的升序链表并返回。
 * 新链表是通过拼接给定的两个链表的所有节点组成的。
 * 
 * 解题思路：
 * 1. 创建虚拟头节点 dummy，简化边界处理
 * 2. 使用双指针分别指向两个链表的当前节点
 * 3. 比较两个指针的值，将较小的节点接到结果链表
 * 4. 移动对应指针，直到某个链表遍历完
 * 5. 将另一个链表的剩余部分接到结果链表
 * 6. 时间复杂度：O(m+n)，空间复杂度：O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

// 链表节点定义
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * 函数功能：合并两个有序链表
 * 参数：
 *   - l1: 第一个有序链表
 *   - l2: 第二个有序链表
 * 返回值：合并后的有序链表头节点
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // 创建虚拟头节点，简化边界处理
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    // 双指针遍历两个链表
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    // 连接剩余部分（其中一个链表已遍历完）
    current->next = (l1 != nullptr) ? l1 : l2;
    
    // 返回真正的头节点（跳过虚拟节点）
    return dummy->next;
}

/**
 * 辅助函数：创建链表
 */
ListNode* createList(const vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    return head;
}

/**
 * 辅助函数：打印链表
 */
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    // 加速输入输出流
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    // 读取两个链表的长度
    cin >> n >> m;
    
    // 读取第一个链表
    vector<int> values1(n);
    for (int i = 0; i < n; i++) {
        cin >> values1[i];
    }
    
    // 读取第二个链表
    vector<int> values2(m);
    for (int i = 0; i < m; i++) {
        cin >> values2[i];
    }
    
    // 创建链表
    ListNode* l1 = createList(values1);
    ListNode* l2 = createList(values2);
    
    // 合并链表
    ListNode* result = mergeTwoLists(l1, l2);
    
    // 打印结果
    printList(result);
    
    return 0;
}

/*
 * 测试样例：
 * 输入：
 * 3 3
 * 1 3 5
 * 2 4 6
 * 
 * 输出：
 * 1 -> 2 -> 3 -> 4 -> 5 -> 6
 */
