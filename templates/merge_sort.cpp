/*
 * 归并排序模板
 * 
 * 时间复杂度：O(n log n)（所有情况）
 * 空间复杂度：O(n)
 * 稳定性：稳定
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 合并函数：将两个有序数组合并为一个有序数组
 * 参数：
 *   - arr: 原数组
 *   - left: 左半部分起始索引
 *   - mid: 左半部分结束索引
 *   - right: 右半部分结束索引
 */
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // 左半部分长度
    int n2 = right - mid;     // 右半部分长度
    
    // 创建临时数组
    vector<int> L(n1), R(n2);
    
    // 复制数据到临时数组
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    // 合并两个有序数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    // 复制剩余元素
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

/**
 * 归并排序递归函数
 * 参数：
 *   - arr: 待排序数组
 *   - left: 起始索引
 *   - right: 结束索引
 */
void mergeSortRecursive(vector<int>& arr, int left, int right) {
    if (left < right) {
        // 计算中间位置
        int mid = left + (right - left) / 2;
        
        // 递归排序左半部分
        mergeSortRecursive(arr, left, mid);
        // 递归排序右半部分
        mergeSortRecursive(arr, mid + 1, right);
        
        // 合并两个有序部分
        merge(arr, left, mid, right);
    }
}

/**
 * 归并排序主函数
 * 参数：
 *   - arr: 待排序数组
 */
void mergeSort(vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    mergeSortRecursive(arr, 0, arr.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    mergeSort(arr);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
