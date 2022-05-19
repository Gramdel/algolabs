#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Vertex {
    bool is_visited = false;
};

vector<Vertex> graph;
int **fuel_matrix;

int fly(int start_index, int fuel) {
    int result = 0;
    if (!graph[start_index].is_visited) {
        result++;
        graph[start_index].is_visited = true;
        for (int i = 0; i < graph.size(); i++) {
            if (i != start_index && fuel_matrix[start_index][i] <= fuel) {
                result += fly(i, fuel);
            }
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

        int result = fly(0, mid);
        if (result == n) {
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
