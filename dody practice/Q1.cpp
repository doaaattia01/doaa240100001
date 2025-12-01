#include <iostream>

void solve() {
    int A, B;

    if (std::cin >> A >> B) {
        int sum = A + B;
        std::cout << sum << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}