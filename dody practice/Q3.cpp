#include <iostream>
#include <cmath>
#include <limits>

long long custom_power(int a, int b) {
    if (b == 0) return 1;
    if (a == 1) return 1;

    long long result = 1;
    long long LLONG_MAX = std::numeric_limits<long long>::max();

    for (int i = 0; i < b; ++i) {
        if (result > LLONG_MAX / a) {
            return LLONG_MAX;
        }
        result *= a;
    }
    return result;
}

void solve() {
    int a, b;
    if (!(std::cin >> a >> b)) {
        return;
    }

    long long term_ab = custom_power(a, b);
    long long term_ba = custom_power(b, a);
    
    long long S = term_ab - term_ba;

    std::cout << S << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}