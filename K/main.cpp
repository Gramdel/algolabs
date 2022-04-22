#include <iostream>
#include <list>

using namespace std;

struct block {
    int start;
    int end;
    bool isFree;

    int calcSize() const {
        return end + 1 - start;
    }
};

list<block> blocks;
int *history;

int reserve_block(int size) {
    for (auto b = blocks.begin(); b != blocks.end(); b++) {
        if (b->isFree) {
            if (b->calcSize() < size) {
                continue;
            } else {
                if (b->calcSize() > size) {
                    blocks.emplace(next(b), block{b->start + size, b->end, true});
                    b->end = b->start + size - 1;
                }
                b->isFree = false;
                return b->start;
            }
        }
    }
    return -1;
}

void free_block(int id) {
    if (history[id]) {
        for (auto b = blocks.begin(); b != blocks.end(); b++) {
            if (b->start == history[id]) {
                b->isFree = true;
                if (b != blocks.end() && next(b)->isFree) {
                    next(b)->start = b->start;
                    b = next(b);
                    blocks.erase(prev(b));
                }
                if (b != blocks.begin() && prev(b)->isFree) {
                    prev(b)->end = b->end;
                    blocks.erase(b);
                }
                return;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    blocks.push_back({1, n, true});
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