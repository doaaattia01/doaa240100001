#include <iostream>
#include <algorithm>

typedef long long ll;

// Function to calculate Z(N) - the number of trailing zeros in N!
ll count_trailing_zeros(ll n) {
    ll count = 0;
    ll p = 5;
    while (n / p >= 1) {
        count += n / p;
        p *= 5;
    }
    // Safety break for very large N, though N <= 5*10^8 is handled by ll
    if (p / 5 > n) return count;
    return count;
}

void solve() {
    ll Q;
    if (!(std::cin >> Q)) {
        return;
    }

    if (Q == 0) {
        std::cout << 0 << std::endl;
        return;
    }

    ll L = 1;
    ll R = 500000000; // Safe upper bound for N when Q <= 10^8 (approx 5*Q)
    ll N_min = -1;

    // Binary search for the smallest N such that Z(N) >= Q
    while (L <= R) {
        ll M = L + (R - L) / 2;
        ll Z_M = count_trailing_zeros(M);

        if (Z_M < Q) {
            L = M + 1;
        } else {
            N_min = M;
            R = M - 1;
        }
    }

    // Check the final candidate
    if (N_min != -1 && count_trailing_zeros(N_min) == Q) {
      
        
        std::cout << N_min << std::endl;
    } else {
        // Z(N_min) > Q, meaning Q was skipped (e.g., Q=2 when Z(N) jumps from 1 to 3)
        std::cout << "No solution" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}