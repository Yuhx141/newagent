/*
 * 深度优先搜索 (DFS) 模板
 * 
 * 应用场景：
 * - 图的遍历
 * - 连通性判断
 * - 拓扑排序
 * - 求解数独、N 皇后等问题
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * DFS 递归函数
 * 参数：
 *   - graph: 邻接表表示的图
 *   - node: 当前访问的节点
 *   - visited: 访问标记数组
 */
void dfs(const vector<vector<int>>& graph, int node, vector<bool>& visited) {
    // 标记当前节点已访问
    visited[node] = true;
    cout << node << " ";  // 访问当前节点
    
    // 访问所有未访问的邻接节点
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

/**
 * DFS 迭代版本（使用栈）
 * 参数：
 *   - graph: 邻接表表示的图
 *   - start: 起始节点
 */
void dfsIterative(const vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> stack;
    
    stack.push_back(start);
    
    while (!stack.empty()) {
        int node = stack.back();
        stack.pop_back();
        
        if (visited[node]) {
            continue;
        }
        
        visited[node] = true;
        cout << node << " ";
        
        // 注意：栈是后进先出，所以要逆序添加邻接节点
        for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
            if (!visited[*it]) {
                stack.push_back(*it);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    // n: 节点数，m: 边数
    cin >> n >> m;
    
    // 邻接表表示图
    vector<vector<int>> graph(n);
    
    // 读入边
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // 无向图，如果是有向图去掉这行
    }
    
    cout << "DFS 遍历结果：";
    vector<bool> visited(n, false);
    
    // 从节点 0 开始 DFS
    dfs(graph, 0, visited);
    cout << endl;
    
    return 0;
}

/*
 * 测试样例：
 * 输入：
 * 5 5
 * 0 1
 * 0 2
 * 1 3
 * 1 4
 * 2 4
 * 
 * 输出：
 * DFS 遍历结果：0 1 3 4 2
 */
