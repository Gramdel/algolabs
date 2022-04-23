#include <iostream>
#include <list>
#include <map>

using namespace std;

struct block {
    int start;
    int end;
    bool isFree;

    int calcSize() const {
        return end + 1 - start;
    }
};

map<int, block> block_map;
multimap<int, int> block_size;
int *history;

int reserve_block(int size) {
    auto it = block_size.lower_bound(size);
    while (it != block_size.end() && it != prev(block_size.end()) && next(it)->second < it->second) {
        it = next(it);
    }

    int start = -1;
    if (it != block_size.end()) {
        if (it->first > size) {
            block_size.insert({it->first - size, it->second + size});
            block_map[it->second + size] = {it->second + size, block_map[it->second].end, true};
            block_map[it->second].end = it->second + size - 1;
        }
        block_map[it->second].isFree = false;
        start = it->second;
        block_size.erase(it);
    }
    return start;
}

void free_block(int id) {
    if (history[id]) {
        auto b = block_map.find(history[id]);
        b->second.isFree = true;
        if (b != prev(block_map.end()) && next(b)->second.isFree) {
            auto range = block_size.equal_range(next(b)->second.calcSize());
            for (auto it = range.first; it != range.second; it++) {
                if (it->second == next(b)->second.start) {
                    block_size.erase(it);
                    break;
                }
            }
            int end = next(b)->second.end;
            block_map.erase(next(b));
            b->second.end = end;
        }
        if (b != block_map.begin() && prev(b)->second.isFree) {
            auto range = block_size.equal_range(prev(b)->second.calcSize());
            for (auto it = range.first; it != range.second; it++) {
                if (it->second == prev(b)->second.start) {
                    block_size.erase(it);
                    break;
                }
            }
            int start = prev(b)->second.start;
            block_map.erase(prev(b));
            b->second.start = start;
        }
        block_size.insert({b->second.calcSize(), b->second.start});
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    block_map[1] = {1, n, true};
    block_size.insert({n, 1});
    history = new int[m];
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) {
            history[i] = reserve_block(tmp);
            cout << history[i] << endl;
        } else {
            history[i] = -1;
            free_block(tmp * (-1) - 1);
        }
    }
    delete[] history;
    return 0;
}