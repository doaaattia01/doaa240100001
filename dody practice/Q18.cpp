#include <iostream>
#include <algorithm>

void solve() {
    int S, P;
    if (!(std::cin >> S >> P)) {
        return;
    }

    int lateness_seconds = P - S;
    int cups_owed = 0;

    if (lateness_seconds <= 0) {
        cups_owed = 0;
    } else if (lateness_seconds >= 1800) {  
        cups_owed = 4;
    } else if (lateness_seconds >= 900) {
        cups_owed = 3;
    } else if (lateness_seconds >= 300) { 
        cups_owed = 2;
    } else { 
        cups_owed = 1;
    }

    std::cout << cups_owed << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
