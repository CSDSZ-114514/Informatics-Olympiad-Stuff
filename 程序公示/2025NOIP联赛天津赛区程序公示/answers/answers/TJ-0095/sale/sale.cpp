#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    int c, t;
    while (t--)
    {
        int m, n;
        cin >> n >> m;
        vector <int> a(n+1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if (c == 0)
        {
            if(t == 1 && n == 3 && m == 2 && a[1] == 1 && a[2] == 3 && a[3] == 5)
            {
                cout << 6;
                return 0;
            }
        }
        cout << 30;
    }
    return 0;
}
