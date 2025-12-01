#include <iostream>
#include <vector>
#include <string>

void solve() {
    int N, M;
    if (!(std::cin >> N >> M)) {
        return;
    }

    std::vector<std::string> phrases(M);
    for (int i = 0; i < M; ++i) {
        if (!(std::cin >> phrases[i])) {
            return;
        }
    }

    int final_index = (N - 1) % M;

    std::cout << phrases[final_index] << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}