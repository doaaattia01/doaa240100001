#include <iostream>
#include <vector>

void solve() {
    int N;
    if (!(std::cin >> N) || N < 1) {
        return;
    }

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        if (!(std::cin >> A[i])) {
            return;
        }
    }

    long long inversion_count = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (A[i] > A[j]) {
                inversion_count++;
            }
        }
    }

    std::cout << inversion_count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}