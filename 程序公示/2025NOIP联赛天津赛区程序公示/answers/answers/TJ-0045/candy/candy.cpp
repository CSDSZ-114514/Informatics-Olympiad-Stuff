#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 5, M = 1e7 + 5;

struct candy
{
    int o, e, all, idx;
}a[N];

struct node
{
	int w, id;

	bool operator < (const node & other) const
	{
		return w > other.w;
	}
};

int dp[M][2];
unordered_map<int, bool> freq;
priority_queue<node> pq;

int v(int x)
{
	if(freq[x] & 1) return a[x].o;
	else return a[x].e;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    int n, ans = 0;
    ll m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].o >> a[i].e;
        a[i].all = a[i].o + a[i].e;
        a[i].idx = i;
        freq[i] = 1;
        pq.push({a[i].o, i});
    }

    while(!pq.empty() and m >= 0)
    {
    	node now = pq.top();
    	pq.pop();
    	m -= now.w;
    	ans++;
    	pq.push({a[now.id].e, now.id});
	}
	cout << ans;
//    for(int i = 1; i <= m; i++)
//    {
//    	cout << "***" << i << endl;
//    	for(int j = 1; j <= n; j++)
//    	{
//			int k = i;
//			cout << j << endl;
//			if(k < v(j)) dp[i][j % 2] = dp[i][(j - 1) % 2];
//			else
//			{
//				while(k >= v(j))
//				{
//					cout << "*" << k << endl;
//					int maxx = max(dp[i][(j - 1) % 2], dp[i - v(j)][j % 2] + v(j));
//    				if(maxx == dp[i - v(j)][(j - 1) % 2] + v(j))
//    				{
//    					k -= v(j);
//    					dp[i][j % 2] = maxx;
//    					freq[j] = (freq[j] + 1) % 2;
//					}
//					else
//					{
//						dp[i][j % 2] = dp[i][(j - 1) % 2];
//						break;
//					}
//				}
//				for(int i = 1; i <= m; i++)
//				{
//					for(int j = 0; j < 2; j++) cout << dp[i][j] << " ";
//					cout <<endl;
//				}
//			}
//		}
//	}
//	for(int i = 1; i <= m; i++)
//	{
//		for(int j = 0; j < 2; j++) cout << dp[i][j] << " ";
//		cout <<endl;
//	}
//	cout << max(dp[m][0], dp[m][1]) << endl;



//    sort(a + 1, a + n + 1, [](candy x, candy y)
//    {
//        return x.all < y.all;
//    });
//    for(int i = 1; i <= n; i++) cout << "a[" << a[i].idx << "].all = " << a[i].all << endl;
//    ans += m / a[1].all * 2;
//    m %= a[1].all;
//    sort(a + 1, a + n + 1, [](candy x, candy y)
//    {
//        if(x.o == y.o) return x.e < y.e;
//        return x.o < y.o;
//    });
//    for(int i = 1; i <= n; i++) cout << "a[" << a[i].idx << "].o = " << a[i].o << ", .e = " << a[i].e << endl;
}
