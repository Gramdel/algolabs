#include <iostream>
#include <vector>

using namespace std;

struct block {
    int start;
    int end;
    bool isFree;

    int calcSize() const {
        return end + 1 - start;
    }
};

vector<block> blocks;
vector<int> history;

int reserve_block(int size) {
    for (int i = 0; i < blocks.size(); i++) {
        if (blocks[i].isFree) {
            if (blocks[i].calcSize() < size) {
                continue;
            } else {
                if (blocks[i].calcSize() > size) {
                    blocks.insert(blocks.begin() + i + 1, {blocks[i].start + size, blocks[i].end, true});
                    blocks[i].end = blocks[i].start + size - 1;
                }
                blocks[i].isFree = false;
                return blocks[i].start;
            }
        }
    }
    return -1;
}

void free_block(int id) {
    if (history[id]) {
        for (int i = 0; i < blocks.size(); i++) {
            if (blocks[i].start == history[id]) {
                blocks[i].isFree = true;
                if (i < blocks.size() - 1 && blocks[i + 1].isFree) {
                    blocks[i + 1].start = blocks[i].start;
                    blocks.erase(blocks.begin() + i);
                }
                if (i > 0 && blocks[i - 1].isFree) {
                    blocks[i - 1].end = blocks[i].end;
                    blocks.erase(blocks.begin() + i);
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
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) {
            history.push_back(reserve_block(tmp));
            cout << history.back() << endl;
        } else {
            history.push_back(-1);
            free_block(tmp * (-1) - 1);
        }
    }
    return 0;
}