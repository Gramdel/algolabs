#include <iostream>
#include <vector>
#include <list>

using namespace std;

enum class color {
    none, red, blue
};

struct vertex {
    color color = color::none;
    bool visited = false;
    vector<int> neighbours;
};

bool draw(vertex &u, color prev_color, vector<vertex> &graph) {
    if (u.visited) {
        return u.color != prev_color;
    }

    u.visited = true;
    u.color = prev_color == color::red ? color::blue : color::red;
    if (!u.neighbours.empty()) {
        for (auto it: u.neighbours) {
            bool check = draw(graph[it], u.color, graph);
            if (!check) {
                return false;
            }
        }
        return true;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vertex> graph(n);

    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        graph[v - 1].neighbours.push_back(u - 1);
        graph[u - 1].neighbours.push_back(v - 1);
    }

    bool check = true;
    for (int i = 0; i < n; i++) {
        vertex v = graph[i];
        if (!v.visited) {
            v.visited = true;
            v.color = color::red;

            if (!v.neighbours.empty()) {
                for (auto it: v.neighbours) {
                    check = draw(graph[it], v.color, graph);
                    if (!check) {
                        break;
                    }
                }
            }
        }
    }
    cout << (check ? "YES" : "NO") << endl;

    return 0;
}
