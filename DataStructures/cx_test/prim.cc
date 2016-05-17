#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Edge {
    int vertex, weight;
};

class Graph {
private:
    int n;
    bool * visited;
    vector<Edge> * edges;
public:
    int * dist;
    Graph (int input_n) {
        n = input_n;
        edges = new vector<Edge>[n];
        dist = new int[n];
        visited = new bool[n];
        memset(visited, false, n * sizeof(bool));
        memset(dist, 0x3f, n * sizeof(int));
    }
    ~Graph() {
        delete[] dist;
        delete[] visited;
        delete[] edges;
    }
    void insert(int x, int y, int weight) {
        Edge a, b;
        a.vertex = y;
        b.vertex = x;
        a.weight = b.weight = weight;
        edges[x].push_back(a);
        edges[y].push_back(b);
    }
    int prim(int v) {
        int total_weight = 0;
        dist[v] = 0;
        for (int i = 0; i < n; ++i) {
            int min_dist = INF, min_vertex;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && dist[j] < min_dist) {
                    min_dist = dist[j];
                    min_vertex = j;
                }
            }
            total_weight += min_dist;
            visited[min_vertex] = 1;
            for (vector<Edge>::iterator it = edges[min_vertex].begin(); it != edges[min_vertex].end(); ++it) {
                if (!visited[it->vertex] && it->weight < dist[it->vertex]) {
                    dist[it->vertex] = it->weight;
                }
            }
        }
        return total_weight;
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g.insert(a, b, c);
    }
    cout << g.prim(0) << endl;
    return 0;
}
