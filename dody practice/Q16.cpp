#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

string solve_case(int X_orig) {
    long long X = X_orig;
    int count = 0;

    for (long long P = 2; P * P <= X; ++P) {
        while (X % P == 0) {
            count++;
            X /= P;
            
            if (count > 2) {
                return "No";
            }
        }
    }

    if (X > 1) {
        count++;
    }

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
