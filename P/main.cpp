#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Vertex {
    bool is_visited = false;
    set<int> neighbours;
};

vector<Vertex> graph;
int **fuel_matrix;

bool fly(int from_index, int to_index, int fuel) {
    if (fuel_matrix[from_index][to_index] > fuel) {
        return false;
    }

    if (!graph[to_index].is_visited) {
        graph[to_index].is_visited = true;
        for (int i = 0; i < graph.size(); i++) {
            if (i != to_index) {
                bool check = fly(to_index, i, fuel);
                if (!check) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    graph.resize(n);
    fuel_matrix = new int *[n];
    int min = INT_MAX;
    int max = 0;

    for (int i = 0; i < n; i++) {
        fuel_matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            fuel_matrix[i][j] = tmp;

            if (i != j) {
                if (tmp < min) {
                    min = tmp;
                }
                if (tmp > max) {
                    max = tmp;
                }
                graph[i].neighbours.insert(j);
            }
        }
    }

    int l = min, r = max, mid;
    while (r > l) {
        mid = l + (r - l + 1) / 2;

        bool check = fly(0, 1, r);
        if (check) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    cout << l << endl;

    for (int i = 0; i < n; ++i) {
        delete[] fuel_matrix[i];
    }
    delete fuel_matrix;

    return 0;
}
