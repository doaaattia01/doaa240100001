#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, int>> result_pairs;

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

    vector<bool> is_prime = sieve(N);

    for (int B = 2; B <= N - 2; ++B) {
        if (is_prime[B]) {
            int Sum = 2 + B;
            
            if (is_prime[Sum]) {
                result_pairs.push_back({2, B});
            }
        }
    }

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
