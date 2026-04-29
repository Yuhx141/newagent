/*
 * 广度优先搜索 (BFS) 模板
 * 
 * 应用场景：
 * - 图的层次遍历
 * - 最短路径（无权图）
 * - 最小步数问题
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * BFS 函数
 * 参数：
 *   - graph: 邻接表表示的图
 *   - start: 起始节点
 */
void bfs(const vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    
    // 起始节点入队
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        cout << node << " ";  // 访问当前节点
        
        // 将所有未访问的邻接节点入队
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

/**
 * BFS 求最短路径
 * 参数：
 *   - graph: 邻接表表示的图
 *   - start: 起始节点
 *   - target: 目标节点
 * 返回值：从 start 到 target 的最短距离
 */
int bfsShortestPath(const vector<vector<int>>& graph, int start, int target) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> dist(n, -1);  // 距离数组，-1 表示未访问
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        // 找到目标节点
        if (node == target) {
            return dist[node];
        }
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    
    return -1;  // 无法到达
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    cout << "BFS 遍历结果：";
    bfs(graph, 0);
    cout << endl;
    
    int target;
    cin >> target;
    int distance = bfsShortestPath(graph, 0, target);
    cout << "从 0 到 " << target << " 的最短距离：" << distance << endl;
    
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
 * 3
 * 
 * 输出：
 * BFS 遍历结果：0 1 2 3 4
 * 从 0 到 3 的最短距离：2
 */
