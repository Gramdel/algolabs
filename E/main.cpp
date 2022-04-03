#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);
    for (auto &el: stalls) {
        cin >> el;
    }
    sort(stalls.begin(), stalls.end());

    int mid, l = 1, r = stalls.back() - stalls.front();
    while (r > l) {
        mid = l + (r - l + 1) / 2;
        int cows = 1;
        int last_stall = 0;
        for (int i = 1; i < n; i++) {
            if (stalls[i] - stalls[last_stall] >= mid) {
                last_stall = i;
                cows++;
                if (cows == k) {
                    break;
                }
            }
        }
        if (cows < k) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    cout << l;

    return 0;
}