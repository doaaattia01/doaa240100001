#include <iostream>
#include <string>
#include <vector>

std::string pluralize(std::string word) {
    int len = word.length();
    if (len < 2) return word + "s";

    if (len >= 2) {
        std::string end2 = word.substr(len - 2);
        if (end2 == "ch" || word.back() == 'x' || word.back() == 's' || word.back() == 'o') {
            return word + "es";
        }
    }

    if (word.back() == 'f') {
        if (len >= 2 && word[len - 2] != 'f') { 
            return word.substr(0, len - 1) + "ves";
        }
    }
    if (len >= 2 && word.substr(len - 2) == "fe") {
        return word.substr(0, len - 2) + "ves";
    }

    if (word.back() == 'y') {
        return word.substr(0, len - 1) + "ies";
    }

    return word + "s";
}

void solve() {
    int n;
    if (!(std::cin >> n) || n < 1) {
        return;
    }

    for (int i = 0; i < n; ++i) {
        std::string word;
        if (std::cin >> word) {
            std::cout << pluralize(word) << std::endl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
