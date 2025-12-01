#include <iostream>
#include <string>
#include <vector>

std::string pluralize(std::string word) {
    int len = word.length();
    if (len < 2) return word + "s";

    // 1. Ends with ch, x, s, o -> add es
    if (len >= 2) {
        std::string end2 = word.substr(len - 2);
        if (end2 == "ch" || word.back() == 'x' || word.back() == 's' || word.back() == 'o') {
            return word + "es";
        }
    }

    // 2. Ends with f or fe -> change to ves
    if (word.back() == 'f') {
        if (len >= 2 && word[len - 2] != 'f') { // Ensures it's 'f' and not 'ff' (e.g., 'cliff')
            return word.substr(0, len - 1) + "ves";
        }
    }
    if (len >= 2 && word.substr(len - 2) == "fe") {
        return word.substr(0, len - 2) + "ves";
    }

    // 3. Ends with y -> change to ies
    if (word.back() == 'y') {
        // Assume 'y' always follows a consonant or a vowel, and change it.
        // Simple model: just check the last letter.
        return word.substr(0, len - 1) + "ies";
    }

    // 4. All other cases -> add s
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