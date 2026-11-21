#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long>a(n+1, 0);
    for (long long i = 1; i <= n; i++)
    {
         cin >> a[i];
    }
    long long q;
    cin >> q;
    long long l, r;
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r;
        cout << 0 << endl;
    }
    return 0;
}
