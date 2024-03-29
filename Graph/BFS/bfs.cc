#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 邻接表
vector<vector<int>> graph;

// 标记节点是否被访问过
vector<bool> visited;

// 广度优先搜索
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "访问节点: " << node << endl;

        // 遍历当前节点的邻居节点
        for (const auto& e : graph[node]) {
            // 如果邻居节点未被访问过，则标记并加入队列
            if (!visited[e]) {
                q.push(e);
                visited[e] = true;
            }
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

    // 从节点0开始广度优先搜索
    bfs(0);

    return 0;
}
