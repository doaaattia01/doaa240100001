#include <iostream>

void solve() {
    int K;
    if (!(std::cin >> K) || K <= 0) {
        return;
    }

    int N = K + 2;

    long long F_prev = 1; 
    long long F_curr = 1;
    long long F_next = 0;

    if (N == 1) {
        F_next = 1;
    } else if (N == 2) {
        F_next = 1;
    } else {
        for (int i = 3; i <= N; ++i) {
            F_next = F_prev + F_curr;
            F_prev = F_curr;
            F_curr = F_next;
        }
    }

    long long S = F_curr - 1;

    std::cout << S << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}