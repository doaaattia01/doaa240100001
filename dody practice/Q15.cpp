#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Global vector to store the pairs
vector<pair<int, int>> result_pairs;

// Sieve of Eratosthenes to pre-calculate primes up to N
vector<bool> sieve(int N) {
    vector<bool> is_prime(N + 1, true);
    if (N >= 0) is_prime[0] = false;
    if (N >= 1) is_prime[1] = false;
    
    for (int p = 2; p * p <= N; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= N; i += p)
                is_prime[i] = false;
        }
    }
    return is_prime;
}

void solve() {
    int N;
    if (!(cin >> N) || N < 1) {
        cout << 0 << endl;
        return;
    }

    // Step 1: Generate primes up to N
    vector<bool> is_prime = sieve(N);

    // Step 2: Iterate through possible B primes
    // Since A=2, the maximum value for B is N-2.
    for (int B = 2; B <= N - 2; ++B) {
        if (is_prime[B]) {
            int Sum = 2 + B;
            
            // Step 3 & 4: Check if Sum is prime and satisfies Sum <= N
            if (is_prime[Sum]) {
                // Pair is (A, B) = (2, B). Since 2 <= B, this is valid.
                result_pairs.push_back({2, B});
            }
        }
    }

    // Output the results
    cout << result_pairs.size() << endl;
    for (const auto& pair : result_pairs) {
        cout << pair.first << " " << pair.second << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}