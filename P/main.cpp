#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int max = 0;
    for (int i = 0; i < n; i++) {
        int min = INT32_MAX;
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp && tmp < min) {
                min = tmp;
            }
        }
        if (min > max) {
            max = min;
        }
    }
    cout << max;

    return 0;
}
