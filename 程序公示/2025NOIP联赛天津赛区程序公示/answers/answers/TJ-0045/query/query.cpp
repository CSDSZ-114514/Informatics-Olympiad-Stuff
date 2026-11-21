#include<bits/stdc++.h>
#define ull unsigned long long

using namespace std;

const int N = 5e4 + 5;
const ull mod = (1 << 64);
int n, q;
int a[N];
ull s[N];
unordered_map<int, int> ktoi;
ull spcA;

int main()
{
    freopen("query4.in", "r", stdin);
    freopen("query.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        ktoi[a[i]] = i;
    }
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << l << " " << r << "\n";
        int lim = r - l + 1;
        // ktoi[i]
        if(l == r)
        {
            //if(spcA) cout << spcA << "\n";
            //else
            //{
                for(int i = 1; i <= n; i++)
                {
                    if(a[i] >= 0)
                }
                cout << spcA << "\n";
            //}
        }
    }
}
