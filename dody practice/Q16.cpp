#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

string solve_case(int X_orig) {
    long long X = X_orig;
    int count = 0;

    // Iterate through potential prime factors up to sqrt(X)
    for (long long P = 2; P * P <= X; ++P) {
        // Factor out the current prime P
        while (X % P == 0) {
            count++;
            X /= P;
            
            // Optimization: If we already found > 2 factors, stop immediately
            if (count > 2) {
                return "No";
            }
        }
    }

    // Handle the remaining factor (if X > 1, the remaining X is the last prime factor)
    if (X > 1) {
        count++;
    }

    // The number is nearly prime if and only if it has exactly 2 prime factors
    if (count == 2) {
        return "Yes";
    } else {
        return "No";
    }
}

void solve() {
    int N;
    if (!(cin >> N)) {
        return;
    }

    for (int i = 0; i < N; ++i) {
        int X;
        if (cin >> X) {
            cout << solve_case(X) << endl;
        }
    }
}

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}