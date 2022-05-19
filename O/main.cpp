#include <iostream>
#include <vector>

using namespace std;

enum class Color {
    none, red, blue
};

struct Vertex {
    Color color = Color::none;
    vector<int> neighbours;
    bool neighbours_colored = false;
};

vector<Vertex> graph;

bool draw(int i) {
    Color needed_color = graph[i].color == Color::red ? Color::blue : Color::red;
    if (!graph[i].neighbours.empty() && !graph[i].neighbours_colored) {
        for (auto it: graph[i].neighbours) {
            if (graph[it].color == Color::none) {
                graph[it].color = needed_color;
            } else if (graph[it].color != needed_color) {
                return false;
            }
        }
        graph[i].neighbours_colored = true;

        for (auto it: graph[i].neighbours) {
            bool check = draw(it);
            if (!check) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);

    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        graph[v - 1].neighbours.push_back(u - 1);
        graph[u - 1].neighbours.push_back(v - 1);
    }

    bool check = true;
    graph[0].color = Color::red;
    for (int i = 0; i < n; i++) {
        check = draw(i);
        if (!check) {
            break;
        }
    }
    cout << (check ? "YES" : "NO") << endl;

    return 0;
}
