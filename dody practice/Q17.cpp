#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Maximum possible value for the friendship number (10^5)
const int MAX_VAL = 100000;

void solve() {
    int n;
    if (!(cin >> n) || n < 1) {
        return;
    }

    // 1. Preprocessing: Store presence of input numbers
    // is_present[i] is true if i is one of the input friendship numbers.
    vector<bool> is_present(MAX_VAL + 1, false);
    int max_input = 0;

    for (int i = 0; i < n; ++i) {
        int a;
        if (cin >> a) {
            is_present[a] = true;
            max_input = max(max_input, a);
        }
    }

    // 2. Iterative Check (Descending Order)
    // Start searching from the highest possible GCD (max_input) down to 1.
    for (int G = max_input; G >= 1; --G) {
        int count_multiples = 0;
        
        // Inner Loop: Check all multiples of G that are less than or equal to max_input
        // k is the multiple (G, 2G, 3G, ...)
        for (int k = G; k <= max_input; k += G) {
            if (is_present[k]) {
                count_multiples++;
            }
        }
        
        // 3. Check Condition: If we found two or more multiples of G
        if (count_multiples >= 2) {
            // G is the largest number that divides at least two input numbers.
            // This guarantees it is the maximum possible GCD among *some* pair.
            cout << G << endl;
            return;
        }
    }

    // This part should technically not be reached if n >= 2, but for completeness:
    // If n=1, or if all numbers are distinct primes with no common factors, the max GCD is 1.
    cout << 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}