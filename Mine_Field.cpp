#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Mine {
    int id, x, y, power;
};

struct Edge {
    int to;
};

struct NodeInfo {
    int id;
    int outdegree;
};

bool isInRange(const Mine& a, const Mine& b) {
    int halfSideLength = a.power / 2;
    int x1 = a.x - halfSideLength;
    int x2 = a.x + halfSideLength;
    int y1 = a.y - halfSideLength;
    int y2 = a.y + halfSideLength;

    return b.x >= x1 && b.x <= x2 && b.y >= y1 && b.y <= y2;
}

void buildGraph(const vector<Mine>& mines, vector<vector<Edge>>& graph, vector<NodeInfo>& nodeInfo) {
    int N = mines.size();
    graph.resize(N);
    nodeInfo.resize(N);

    for (int i = 0; i < N; ++i) {
        nodeInfo[i].id = i;
        nodeInfo[i].outdegree = 0;
        for (int j = 0; j < N; ++j) {
            if (i != j && isInRange(mines[i], mines[j])) {
                graph[i].push_back({j});
                nodeInfo[i].outdegree++;
            }
        }
    }

    sort(nodeInfo.begin(), nodeInfo.end(), [](const NodeInfo& a, const NodeInfo& b) {
        return a.outdegree > b.outdegree;
    });
}

void printAdjacencyListWithOutdegree(const vector<Mine>& mines, const vector<vector<Edge>>& graph, const vector<NodeInfo>& nodeInfo) {
    cout << "Adjacency List with Outdegree:\n";
    for (const NodeInfo& node : nodeInfo) {
        cout << "Mine " << mines[node.id].id << " at (" << mines[node.id].x << "," << mines[node.id].y << ") has outdegree: " << node.outdegree << ", connected to:\n";
        for (const Edge& edge : graph[node.id]) {
            cout << "  -> Mine " << mines[edge.to].id << "\n";
        }
    }
}

void dfs(int node, const vector<vector<Edge>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (const Edge& edge : graph[node]) {
        if (!visited[edge.to]) {
            dfs(edge.to, graph, visited);
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<Mine> mines(N);
        for (int i = 0; i < N; ++i) {
            cin >> mines[i].x >> mines[i].y >> mines[i].power;
            mines[i].id = i + 1;
        }

        vector<vector<Edge>> graph;
        vector<NodeInfo> nodeInfo;
        buildGraph(mines, graph, nodeInfo);

        printAdjacencyListWithOutdegree(mines, graph, nodeInfo);

        // DFS from nodes sorted by outdegree
        vector<bool> visited(N, false);
        int counter = 0;
        for (const NodeInfo& node : nodeInfo) {
            if (!visited[node.id]) {
                dfs(node.id, graph, visited);
                counter++;
            }
        }

        cout << "Minimum Mines to explode: " << counter << endl;
    }

    return 0;
}