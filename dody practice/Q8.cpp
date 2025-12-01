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
    
    // Arrays to track the count of non-bull digits for each number (digits 0-9)
    // counts[i] stores the frequency of digit 'i'
    std::vector<int> secret_counts(10, 0);
    std::vector<int> guess_counts(10, 0);

    // Step 1: Count Bulls and populate frequency arrays for non-bull digits
    for (int i = 0; i < 4; ++i) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            // Convert character digit to integer (e.g., '5' -> 5)
            secret_counts[secret[i] - '0']++;
            guess_counts[guess[i] - '0']++;
        }
    }

    // Step 2: Count Cows from the remaining non-bull digits
    // A cow exists if the same digit appears in both non-bull counts.
    // The number of cows is the minimum frequency of that digit in the two non-bull sets.
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