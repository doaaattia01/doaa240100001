#include <iostream>
#include <algorithm>

void solve() {
    int S, P;
    if (!(std::cin >> S >> P)) {
        return;
    }

    // Calculate lateness in seconds (L)
    int lateness_seconds = P - S;
    int cups_owed = 0;

    // Check lateness against the rules in descending order of penalty
    if (lateness_seconds <= 0) {
        cups_owed = 0;
    } else if (lateness_seconds >= 1800) { // 30 minutes or more
        cups_owed = 4;
    } else if (lateness_seconds >= 900) { // 15 minutes or more
        cups_owed = 3;
    } else if (lateness_seconds >= 300) { // 5 minutes or more
        cups_owed = 2;
    } else { // At least 1 second late, but less than 5 minutes
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