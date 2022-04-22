#include <iostream>
#include <vector>

using namespace std;

struct block {
    size_t id;
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
                    blocks.insert(blocks.begin() + i + 1, {blocks.size(), blocks[i].start + size, blocks[i].end, true});
                    blocks[i].end = blocks[i].start + size - 1;
                }
                blocks[i].isFree = false;
                history.push_back(blocks[i].start);
                return blocks[i].start;
            }
        }
    }
    return -1;
}

void free_block(int id) {
    for (int i = 0; i < blocks.size(); i++) {
        if (blocks[i].start == history[id]) {
            blocks[i].isFree = true;
            return;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    blocks.push_back({blocks.size(), 1, n, true});
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) {
            cout << reserve_block(tmp) << endl;
        } else {
            free_block(tmp*(-1)-1);
        }
    }

    return 0;
}