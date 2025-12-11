//Smallest N with exactly Q trailing zeros in factorial
#include <iostream>
#include <algorithm>

typedef long long ll;

ll count_trailing_zeros(ll n) {
    ll count = 0;
    ll p = 5;
    while (n / p >= 1) {
        count += n / p;
        p *= 5;
    }
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
    ll R = 500000000; 
    ll N_min = -1;

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

    if (N_min != -1 && count_trailing_zeros(N_min) == Q) {
      
        
        std::cout << N_min << std::endl;
    } else {
        std::cout << "No solution" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
