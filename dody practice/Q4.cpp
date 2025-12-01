#include <iostream>

void solve() {
    long long x;
    if (!(std::cin >> x)) {
        return;
    }

    long long N = 2 * x + 1;

    std::cout << N << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}