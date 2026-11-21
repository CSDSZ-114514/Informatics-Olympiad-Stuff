#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e3 + 5, mod = 998244353;
int n, m, ans;
int a[N];
bool w[15][N];

ll qpow(int x, int y)
{
    ll res = 1;
    while(y)
    {
        if(y & 1) res = res * y % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

vector<vector<int> > tmp;


struct tpl
{
    int v;
    double w;
    int id;
};

vector<tpl> node;

void init(int x, int now, int dep)
{
	cout << dep << ": " << now << "\n";
    //vector<int> tmp1, tmp2;
    if(x == n + 1)
    {
        //tmp.push_back(tmp1);
        //tmp.push_back(tmp2);
        return;
    }
    //tmp1.push_back(now);
    //tmp2.push_back(now);
    tmp[dep][x] = now;
    init(x + 1, 1, 2 * dep + 1);
    init(x + 1, 2, 2 * dep + 2);
}

bool operator == (const vector<int> m, const vector<tpl> n)
{
    for(int i = 0; i < m.size(); i++)
    {
        if(m[i] != n[i].w) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        memset(a, 0, sizeof a);
        cin >> n >> m;
        //cout << n << " " << m <<endl;
//        node.resize(n);
        //cout << "victory!\n";
//        for(auto &i : node)
//        {
//        	cout << "node\n";
//            i.v = i.id = 0;
//            i.w = 0.0;
//        }
        for(int i = 0; i < n; i++)
        {
        	//cout <<"n\n";
        	node[i].v = node[i].id = node[i].w = 0;
		}
        tmp.resize(n);
        for(auto &i : tmp) 
		{
			i.resize(n, 0);
			//cout << "tmp\n";
		}
        for(int i = 0; i < n; i++) cin >> a[i];
        if(c == 18) cout << qpow(2, n) % mod << "\n";
        //cout << "1";
        if(c >= 1 and c <= 5)
        {
        	//cout << "1\n";
            init(1, 1, 0);
            init(1, 2, 0);
//            for(auto i : tmp)
//            {
//            	for(auto j : i) cout << j << " ";
//				cout << endl;
//			}
            for(auto i : tmp)
            {
                vector<int> cpy = i;
                sort(cpy.begin(), cpy.end());
                for(int j = 0; j < n; j++)
                {
                    node[j].v = a[j];
                    node[j].w = a[j] / i[j];
                    node[j].id = j;
                }
                sort(node.begin(), node.end(), [](tpl x, tpl y)
                {
                    if(x.v == y.v && x.w == y.w) return x.id < y.id;
                    else
                    {
                        if(x.w == y.w) x.v > y.v;
                        else return x.w > y.w;
                    }
                });
                if(i == node) ans = (ans + 1) % mod;
            }
            cout << ans << "\n";
        }
    }
}
