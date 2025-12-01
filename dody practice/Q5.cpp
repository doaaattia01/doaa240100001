#include <iostream>
#include <cmath>

void solve() {
    int N;
    if (!(std::cin >> N) || N <= 0) {
        return;
    }

    if (N == 1) {
        std::cout << 1 << std::endl;
        return;
    }

    int result = N;
    int temp_N = N;

    for (int p = 2; p * p <= temp_N; ++p) {
        if (temp_N % p == 0) {
            result = result - result / p;
            while (temp_N % p == 0) {
                temp_N /= p;
            }
        }
    }

    if (temp_N > 1) {
        result = result - result / temp_N;
    }

    std::cout << result << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}