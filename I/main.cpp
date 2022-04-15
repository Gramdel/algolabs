#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main() {
    int n, k, p, count = 0;
    cin >> n >> k >> p;

    vector<int> order(p);
    vector<list<int>> distances(n);
    for (int i = 0; i < p; i++) {
        cin >> order[i];
        distances[order[i] - 1].push_back(i);
    }

    map<int, int> floor;
    for (int i = 0; i < p; i++) {
        auto entry = floor.find(distances[order[i] - 1].front());
        if (entry == floor.end()) {
            if (floor.size() == k) {
                floor.erase(prev(floor.end()));
            }
            count++;
        } else {
            floor.erase(entry);
        }
        distances[order[i] - 1].pop_front();
        floor[distances[order[i] - 1].empty() ? 500000 + order[i] : distances[order[i] - 1].front()] = order[i];
    }
    cout << count;

    return 0;
}
