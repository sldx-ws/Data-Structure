#include <iostream>
#include <vector>
using namespace std;

// 邻接表
vector<vector<int>> graph;

// 标记节点是否被访问过
vector<bool> visited;

// 深度优先搜索
void dfs(int node) {
    // 标记当前节点为已访问
    visited[node] = true;
    cout << "访问节点: " << node << endl;

    // 遍历当前节点的邻居节点
    for (int neighbor : graph[node]) {
        // 如果邻居节点未被访问过，则递归访问它
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n = 6;  // 节点数量
    graph.resize(n);
    visited.assign(n, false);

    // 构建图的邻接表
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);
    graph[2].push_back(5);

    // 从节点0开始深度优先搜索
    dfs(0);

    return 0;
}
