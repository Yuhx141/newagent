/*
 * 并查集 (Union-Find) 模板
 * 
 * 支持操作：
 * - 查找（带路径压缩）
 * - 合并（按秩合并）
 * 
 * 时间复杂度：近乎 O(1)（阿克曼函数的反函数）
 * 应用场景：
 * - 连通分量计数
 * - 判断图中是否有环
 * - 最小生成树 (Kruskal 算法)
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 并查集类
 */
class UnionFind {
private:
    vector<int> parent;  // 父节点数组
    vector<int> rank;    // 秩数组（树的高度）
    int count;           // 连通分量数量

public:
    /**
     * 构造函数
     * 参数：
     *   - n: 元素个数
     */
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        rank.resize(n, 0);
        
        // 初始化：每个元素的父节点是自己
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    /**
     * 查找操作（带路径压缩）
     * 参数：
     *   - x: 要查找的元素
     * 返回值：x 的根节点
     */
    int find(int x) {
        // 路径压缩：将路径上的所有节点直接连接到根节点
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    /**
     * 合并操作（按秩合并）
     * 参数：
     *   - x: 第一个元素
     *   - y: 第二个元素
     * 返回值：是否成功合并（原本不在同一集合）
     */
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        // 已经在同一集合
        if (rootX == rootY) {
            return false;
        }
        
        // 按秩合并：将矮树连接到高树上
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        count--;
        return true;
    }
    
    /**
     * 判断两个元素是否在同一集合
     */
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    
    /**
     * 获取连通分量数量
     */
    int getCount() {
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    // n: 元素个数，m: 操作次数
    cin >> n >> m;
    
    UnionFind uf(n);
    
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        
        if (op == 1) {
            // 合并操作
            uf.unite(x, y);
        } else {
            // 查询操作
            if (uf.connected(x, y)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    
    cout << "连通分量数量：" << uf.getCount() << endl;
    
    return 0;
}

/*
 * 测试样例：
 * 输入：
 * 5 5
 * 1 0 1
 * 1 2 3
 * 2 0 1
 * 2 0 2
 * 1 0 2
 * 
 * 输出：
 * YES
 * NO
 * 连通分量数量：2
 */
