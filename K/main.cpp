#include <iostream>
#include <map>

using namespace std;

map<int, int> by_start;
multimap<int, int> by_size;
pair<int, int> *history;

int reserve_block(int capacity) {
    int start = -1;
    auto by_size_it = by_size.lower_bound(capacity);
    if (by_size_it != by_size.end()) {
        start = by_size_it->second;
        int size = by_size_it->first;
        if (size > capacity) {
            by_size.insert({size - capacity, start + capacity});
            by_start.insert({start + capacity, size - capacity});
        }
    }
    return start;
}

void free_block(int id) {
    if (history[id].first) {
        int start = history[id].first;
        int size = history[id].second;

        auto next = by_start.lower_bound(start);
        auto prev = next == by_start.begin() ? by_start.end() : std::prev(next);

        if (next != by_start.end() && next->first == start + size) {
            size += next->second;
            auto range = by_size.equal_range(next->second);
            for (auto &it = range.first; it != range.second; it++) {
                if (it->second == next->first) {
                    by_size.erase(it);
                    break;
                }
            }
            by_start.erase(next);
        }
        if (prev != by_start.end() && start == prev->second + prev->first) {
            size += prev->second;
            start = prev->first;
            auto range = by_size.equal_range(prev->second);
            for (auto &it = range.first; it != range.second; it++) {
                if (it->second == prev->first) {
                    by_size.erase(it);
                    break;
                }
            }
            by_start.erase(prev);
        }
        by_size.insert({size, start});
        by_start.insert({start, size});
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    by_start.insert({1, n});
    by_size.insert({n, 1});
    history = new pair<int, int>[m];
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) {
            history[i] = {reserve_block(tmp), tmp};
            cout << history[i].first << endl;
        } else {
            history[i] = {-1, tmp};
            free_block(tmp * (-1) - 1);
        }
    }
    delete[] history;
    return 0;
}