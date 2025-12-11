//البرنامج بيحسب أقصى عدد قطع أكل ممكن تتعمل باستخدام 3 مكونات، والنتيجة بتتحدد بأقل مكوّن متاح
#include <iostream>
#include <algorithm>

void solve() {
    int P, M, C, K, R, V;
    
    // Read all six integer inputs
    if (!(std::cin >> P >> M >> C >> K >> R >> V)) {
        return;
    }

    // Calculate the maximum patties based on each ingredient
    // Integer division automatically handles the floor function
    int max_by_flour = P / K;
    int max_by_milk = M / R;
    int max_by_cabbage = C / V;

    // Find the minimum of the three limits
    int max_patties = std::min({max_by_flour, max_by_milk, max_by_cabbage});

    std::cout << max_patties << std::endl;
}

int main() {
    // Optimization for faster I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
