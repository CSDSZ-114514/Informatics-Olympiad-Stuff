#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
struct data{
    int x;
    int y;
    int v;
}arr[100010];
bool cmp1(data a, data b)
{
    return a.v < b.v;
}
bool cmp2(data a, data b)
{
    return a.x < b.x;
}
int main()
{
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
        arr[i].v = arr[i].x+arr[i].y;
    }
    sort(arr+1, arr+n+1, cmp1);
    int base1 = 0, base2 = m;
    for (int i = 1; i <= n; i++)
    {
        int t = base2/arr[i].v;
        base1 += t;
        base2 -= t*arr[i].v;
        if (base2 <= 0)
        {
            break;
        }
    }
    if (base2 == 0)
    {
        cout << base1*2;
        return 0;
    }
    int ans = base1*2, t = base2;
    sort(arr+1, arr+n+1, cmp2);
    for (int i = 1; i <= n; i++)
    {
        if (t < arr[i].x)
        {
            break;
        }
        if (t >= arr[i].x)
        {
            ans++;
            t -= arr[i].x;
        }
    }
    cout << ans;
    return 0;
}
