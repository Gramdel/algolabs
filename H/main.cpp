#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> prices(n);
    for (auto &el: prices) {
        cin >> el;
    }
    sort(prices.rbegin(), prices.rend());

    int count = 1;
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (n >= k) {
            if (count == k) {
                count = 1;
                continue;
            } else {
                count++;
            }
        }
        result+=prices[i];
    }
    cout << result;

    return 0;
}
