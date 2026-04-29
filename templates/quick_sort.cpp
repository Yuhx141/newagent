/*
 * 快速排序模板
 * 
 * 时间复杂度：平均 O(n log n)，最坏 O(n²)
 * 空间复杂度：O(log n)（递归栈）
 * 稳定性：不稳定
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 分区函数：将数组分为小于基准和大于基准的两部分
 * 参数：
 *   - arr: 待排序数组
 *   - low: 起始索引
 *   - high: 结束索引
 * 返回值：基准元素的最终位置
 */
int partition(vector<int>& arr, int low, int high) {
    // 选择最右边元素作为基准
    int pivot = arr[high];
    int i = low - 1;  // i 指向小于 pivot 区域的最后一个元素
    
    for (int j = low; j < high; j++) {
        // 当前元素小于等于基准，放入左侧区域
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // 将基准元素放到中间位置
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

/**
 * 快速排序递归函数
 * 参数：
 *   - arr: 待排序数组
 *   - low: 起始索引
 *   - high: 结束索引
 */
void quickSortRecursive(vector<int>& arr, int low, int high) {
    if (low < high) {
        // 获取分区点
        int pi = partition(arr, low, high);
        
        // 递归排序左半部分
        quickSortRecursive(arr, low, pi - 1);
        // 递归排序右半部分
        quickSortRecursive(arr, pi + 1, high);
    }
}

/**
 * 快速排序主函数
 * 参数：
 *   - arr: 待排序数组
 */
void quickSort(vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    quickSortRecursive(arr, 0, arr.size() - 1);
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
    
    quickSort(arr);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
