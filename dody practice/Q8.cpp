#include <iostream>
#include <string>
#include <vector>

void solve() {
    std::string secret, guess;
    if (!(std::cin >> secret >> guess)) {
        return;
    }

    int bulls = 0;
    int cows = 0;
    
    
    std::vector<int> secret_counts(10, 0);
    std::vector<int> guess_counts(10, 0);

    for (int i = 0; i < 4; ++i) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            secret_counts[secret[i] - '0']++;
            guess_counts[guess[i] - '0']++;
        }
    }

    for (int d = 0; d <= 9; ++d) {
        cows += std::min(secret_counts[d], guess_counts[d]);
    }

    std::cout << bulls << " " << cows << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
