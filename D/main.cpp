#include <iostream>

int main() {
    int a;
    short b, c, d;
    long long k;
    std::cin >> a >> b >> c >> d >> k;

    for (long long i = 1; i <= k; i++) {
        if (a >= (c + d) / b) {
            a = d;
            break;
        }
        if (a <= c / b) {
            a = 0;
            break;
        }
        a = a * b - c;
        if (b == double(c) / a + 1) {
            break;
        }
    }
    std::cout << a;
    return 0;
}