#include <iostream>

void solve() {
    long long N;
    if (!(std::cin >> N) || N <= 0) {
        return;
    }

    long long full_cycles = N / 3;

    long long count = 2 * full_cycles;

    long long remainder = N % 3;

    if (remainder == 2) {
        count += 1;
    }

    std::cout << count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}