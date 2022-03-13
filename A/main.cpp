#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int start = 0;
    int end = 0;
    int prev = 0;
    char same_counter = 1;
    int first_mid;
    int second_mid;

    for (int i = 0; i < n; i++) {
        if (first_mid) {
            if (end - start < i - second_mid) {
                start = second_mid;
                end = i;
            }
        } else {
            end = i;
        }

        if (prev) {
            if (a[i] == prev) {
                same_counter++;
                if (i + 1 < n && a[i + 1] == prev) {
                    if (same_counter == 2) {
                        first_mid = i;
                    }
                    if (same_counter >= 2) {
                        second_mid = i;
                    }
                }
            } else {
                same_counter = 1;
            }
        }
        prev = a[i];
    }

    cout << start + 1 << " " << end + 1;

    delete[] a;

    return 0;
}
