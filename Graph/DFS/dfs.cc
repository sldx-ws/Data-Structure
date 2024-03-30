#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

// 深度优先搜索
void dfs(int node) {
    visited[node] = true;
    cout << "访问节点: " << node << endl;
    
    for (const auto& e : graph[node]) {
        if (!visited[e]) {
            dfs(e);
        }
    }
}

int main() {
    int n = 6;  
    graph.resize(n);
    visited.assign(n, false);

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);
    graph[2].push_back(5);

    dfs(0);

    return 0;
}
