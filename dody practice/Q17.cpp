#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_VAL = 100000;

void solve() {
    int n;
    if (!(cin >> n) || n < 1) {
        return;
    }

    vector<bool> is_present(MAX_VAL + 1, false);
    int max_input = 0;

    for (int i = 0; i < n; ++i) {
        int a;
        if (cin >> a) {
            is_present[a] = true;
            max_input = max(max_input, a);
        }
    }

    for (int G = max_input; G >= 1; --G) {
        int count_multiples = 0;
        
        for (int k = G; k <= max_input; k += G) {
            if (is_present[k]) {
                count_multiples++;
            }
        }
        
        if (count_multiples >= 2) {
            cout << G << endl;
            return;
        }
    }

    cout << 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
