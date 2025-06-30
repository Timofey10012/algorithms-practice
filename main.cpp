#include <iostream>
#include <vector>
#include <algorithm>

void topolSort(const std::vector<std::vector<int>>& graph, int i, std::vector<bool>& visited, std::vector<int>& result) {
    visited[i] = true;

    for (int num : graph[i]) {
        if (!visited[num]) {
            topolSort(graph, num, visited, result);
        }
    }

    result.push_back(i);
}

int main() {
    int n = 6;
    std::vector<std::vector<int>> graph(n);

    graph[1].emplace_back(2);
    graph[4].emplace_back(5);
    graph[5].emplace_back(3);
    graph[4].emplace_back(1);

    std::vector<int> result;
    result.reserve(n);
    std::vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topolSort(graph, i, visited, result);
        }
    }

    std::reverse(result.begin(), result.end());

    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
