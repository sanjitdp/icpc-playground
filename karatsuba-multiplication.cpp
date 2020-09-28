#include <iostream>
#include <cmath>

float max_len(std::string &m, std::string &n) {
    float m_len = m.length();
    float n_len = n.length();
    float len;
    if (m_len >= n_len) {
        len = m_len;
    } else {
        len = n_len;
    }
    return len;
}

// a multiplication algorithm for x, y with 2^n digits
double karatsuba(std::string &x, std::string &y) {
    std::string a, b, c, d;

    if (x.length() != 1) {
        a = x.substr(0, x.length()/2);
        b = x.substr(x.length()/2);
        c = y.substr(0, y.length()/2);
        d = y.substr(y.length()/2);
    } else {
        return stoi(x) * stoi(y);
    }

    float len = max_len(x, y);
    return karatsuba(a, c) * pow(10, len) + (karatsuba(a, d) + karatsuba(b, c)) * pow(10, len / 2) + karatsuba(b, d);
}

int main() {
    std::string m;
    std::string n;
    std::cin >> m >> n;
    std::cout << karatsuba(m, n);
    return 0;
}
