#include <iostream>
#include <stack>
#include <map>

using namespace std;

struct element {
    char value;
    bool is_trap;
    int id;
};

int main() {
    stack<struct element> line;
    map<int, int> trap_map;
    int animal_count = 0, trap_count = 0;

    struct element tmp = {0};

    while ((tmp.value = (char) getchar()) != '\n') {
        tmp.is_trap = tmp.value <= 'Z';
        tmp.id = tmp.is_trap ? trap_count++ : ++animal_count;

        if (!line.empty() && abs(line.top().value - tmp.value) == 32) {
            if (tmp.is_trap) {
                trap_map[tmp.id] = line.top().id;
            } else {
                trap_map[line.top().id] = tmp.id;
            }
            line.pop();
        } else {
            line.push(tmp);
        }
    }

    if (line.empty()) {
        cout << "Possible" << endl;
        for (const auto &pair: trap_map) {
            cout << pair.second << " ";
        }
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
