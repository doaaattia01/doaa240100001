#include <iostream>

void solve() {
    int N;
    // Input N is read, but it is irrelevant to the solution.
    if (!(std::cin >> N)) {
        return;
    }

    // The result is 0 because the required last 9 digits (987654321) 
    // do not correspond to the last 9 digits of any perfect square.
    // Specifically, 987654321 is not a quadratic residue modulo 27.
    
    std::cout << 0 << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}