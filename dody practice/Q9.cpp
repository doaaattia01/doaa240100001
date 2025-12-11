#include <iostream>
#include <vector>
#include <algorithm>

int find_median_of_three(int a, int b, int c) {
    std::vector<int> numbers = {a, b, c};
    std::sort(numbers.begin(), numbers.end());
    return numbers[1];
}

void solve() {
    int A1, A2, A3;
    int B1, B2, B3;
    int C1, C2, C3;

    if (!(std::cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3 >> C1 >> C2 >> C3)) {
        return;
    }

    int median_A = find_median_of_three(A1, A2, A3);
    int median_B = find_median_of_three(B1, B2, B3);
    int median_C = find_median_of_three(C1, C2, C3);

    int final_median = find_median_of_three(median_A, median_B, median_C);

    std::cout << final_median << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
