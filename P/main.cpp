#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Vertex {
    bool is_visited = false;
};

vector<Vertex> graph;
int **fuel_matrix;

int fly(int start_index, int fuel, bool swap_indexes) {
    int result = 1;
    graph[start_index].is_visited = true;
    for (int i = 0; i < graph.size(); i++) {
        int needed_fuel = swap_indexes ? fuel_matrix[start_index][i] : fuel_matrix[i][start_index];
        if (i != start_index && needed_fuel <= fuel && !graph[i].is_visited) {
            result += fly(i, fuel, swap_indexes);
        }
    }
    return result;
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
            }
        }
    }

    int l = min, r = max, mid;
    while (r > l) {
        mid = l + (r - l) / 2;

        for (auto &i: graph) {
            i.is_visited = false;
        }
        int result = fly(0, mid, false);

        for (auto &i: graph) {
            i.is_visited = false;
        }
        result += fly(0, mid, true);

        if (result == 2 * n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if (n == 1) {
        cout << 0 << endl;
    } else {
        cout << l << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] fuel_matrix[i];
    }
    delete fuel_matrix;

    return 0;
}
