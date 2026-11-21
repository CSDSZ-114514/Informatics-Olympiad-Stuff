#include <iostream>
#define file_io(id) do { \
    freopen(id".in", "r", stdin); freopen(id".out", "w", stdout); \
} while(false)
using namespace std;
int main() {
    file_io("query");
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return 0;
}
//Tags: I Love CCF, CCF, NOIP, CSP
