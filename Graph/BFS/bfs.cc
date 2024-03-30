#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "访问节点: " << node << endl;

        for (const auto& e : graph[node]) {
            if (!visited[e]) {
                q.push(e);
                visited[e] = true;
            }
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

    bfs(0);

    return 0;
}
