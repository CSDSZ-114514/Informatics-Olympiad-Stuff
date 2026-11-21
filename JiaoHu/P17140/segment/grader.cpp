#include <bits/stdc++.h>
#include "segment.h"

signed main() {
    int c, t;
    std::cin >> c >> t;
    init(c, t);
    for (int _ = 0; _ < t; _++) {
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) {
            std::cin >> l[i] >> r[i];
        }

        std::vector<int> a = segment(n, m, k, l, r);

        if (static_cast<int>(a.size()) != k + 1) {
            std::cout << "The length of a is not k + 1.\n";
            continue;
        }

        for (int i = 1; i <= k; i++) {
            std::cout << a[i] << " \n"[i == k];
        }
    }
    return 0;
}
