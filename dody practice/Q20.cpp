#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long ll;

ll combinations(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n / 2) {
        k = n - k;
    }
    ll res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

ll factorial(int k) {
    ll res = 1;
    for (int i = 2; i <= k; ++i) {
        res *= i;
    }
    return res;
}

void solve() {
    int n, k;
    if (!(std::cin >> n >> k)) {
        return;
    }

    if (k == 0) {
        std::cout << 1 << std::endl;
        return;
    }

    if (k > n) {
        std::cout << 0 << std::endl;
        return;
    }

    ll p_nk = 1;
    for (int i = 0; i < k; ++i) {
        p_nk *= (n - i);
    }
    
    ll c_nk = combinations(n, k);

    ll total_ways = p_nk * c_nk;

    std::cout << total_ways << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
