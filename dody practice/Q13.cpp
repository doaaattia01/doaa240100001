#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <limits>

using namespace std;

typedef long long ll;

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll g = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

ll floor_div(ll a, ll b) {
    ll res = a / b;
    if ((a % b != 0) && (a < 0) != (b < 0)) {
        res--;
    }
    return res;
}

ll ceil_div(ll a, ll b) {
    ll res = a / b;
    if ((a % b != 0) && (a > 0) == (b > 0)) {
        res++;
    }
    return res;
}

void solve() {
    ll a, b, c, x1, x2, y1, y2;
    if (!(cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2)) {
        return;
    }

    if (a == 0 && b == 0) {
        cout << (c == 0 ? (x2 - x1 + 1) * (y2 - y1 + 1) : 0) << endl;
        return;
    }
    
    if (a == 0) {
        if ((-c) % b != 0) {
            cout << 0 << endl; return;
        }
        ll y_sol = -c / b;
        cout << (y1 <= y_sol && y_sol <= y2 ? x2 - x1 + 1 : 0) << endl;
        return;
    }

    if (b == 0) {
        if ((-c) % a != 0) {
            cout << 0 << endl; return;
        }
        ll x_sol = -c / a;
        cout << (x1 <= x_sol && x_sol <= x2 ? y2 - y1 + 1 : 0) << endl;
        return;
    }

    ll xg, yg;
    ll g = extended_gcd(abs(a), abs(b), xg, yg);
    
    if (a < 0) xg = -xg;
    if (b < 0) yg = -yg;

    ll neg_c = -c;
    if (neg_c % g != 0) {
        cout << 0 << endl;
        return;
    }

    ll factor = neg_c / g;
    ll x0 = xg * factor;
    ll y0 = yg * factor;

    ll B_prime = b / g;
    ll A_prime = a / g;

    ll k_min_x, k_max_x;

    if (B_prime > 0) {
        k_min_x = ceil_div(x1 - x0, B_prime);
        k_max_x = floor_div(x2 - x0, B_prime);
    } else { 
        k_max_x = floor_div(x1 - x0, B_prime);
        k_min_x = ceil_div(x2 - x0, B_prime);
    }

    ll k_min_y, k_max_y;
    
    if (A_prime > 0) {
        k_min_y = ceil_div(y0 - y2, A_prime);
        k_max_y = floor_div(y0 - y1, A_prime);
    } else { 
        k_max_y = floor_div(y0 - y2, A_prime);
        k_min_y = ceil_div(y0 - y1, A_prime);
    }

    ll k_start = max(k_min_x, k_min_y);
    ll k_end = min(k_max_x, k_max_y);

    if (k_start > k_end) {
        cout << 0 << endl;
    } else {
        cout << k_end - k_start + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}