#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> all_pigs;
    for (int i = 1; i <= n; i++) {
        cin >> all_pigs[i];
    }

    int count = 0;
    vector<bool> checked_pigs(n);
    for (int i = 1; i <= n; i++) {
        vector<int> prev_pigs;
        prev_pigs.push_back(i);

        int curr_pig = i;
        while (true) {
            if (!checked_pigs[curr_pig - 1]) {
                int next_pig = all_pigs[curr_pig];
                if (find(prev_pigs.begin(), prev_pigs.end(), next_pig) == prev_pigs.end()) {
                    curr_pig = next_pig;
                    prev_pigs.push_back(next_pig);
                    continue;
                } else {
                    count++;
                }
            }
            for (auto it: prev_pigs) {
                checked_pigs[it - 1] = true;
            }
            break;
        }

    }
    cout << count;

    return 0;
}
