#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long ll;

// Function to calculate nCk (n choose k)
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
        // Safe multiplication: (n - i + 1) / i
        res = res * (n - i + 1) / i;
    }
    return res;
}

// Function to calculate factorial (k!)
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

    // Edge case: If k=0, there is always 1 way (placing no rooks).
    if (k == 0) {
        std::cout << 1 << std::endl;
        return;
    }

    // Constraint check: Cannot place more rooks than rows/columns
    if (k > n) {
        std::cout << 0 << std::endl;
        return;
    }

    // Calculate P(n, k) = n! / (n - k)!
    ll p_nk = 1;
    for (int i = 0; i < k; ++i) {
        p_nk *= (n - i);
    }
    
    // Calculate C(n, k)
    ll c_nk = combinations(n, k);

    // Final result
    ll total_ways = p_nk * c_nk;

    std::cout << total_ways << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}