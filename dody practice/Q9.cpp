#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the median of three numbers
int find_median_of_three(int a, int b, int c) {
    std::vector<int> numbers = {a, b, c};
    // Sort the numbers in non-descending order
    std::sort(numbers.begin(), numbers.end());
    // The median is the element at index 1 (the middle element)
    return numbers[1];
}

void solve() {
    int A1, A2, A3;
    int B1, B2, B3;
    int C1, C2, C3;

    // Read the three triples from the input
    if (!(std::cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3 >> C1 >> C2 >> C3)) {
        return;
    }

    // Step 1: Find the median of each triple
    int median_A = find_median_of_three(A1, A2, A3);
    int median_B = find_median_of_three(B1, B2, B3);
    int median_C = find_median_of_three(C1, C2, C3);

    // Step 2: Find the median of the three medians
    int final_median = find_median_of_three(median_A, median_B, median_C);

    // Print the final result
    std::cout << final_median << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}