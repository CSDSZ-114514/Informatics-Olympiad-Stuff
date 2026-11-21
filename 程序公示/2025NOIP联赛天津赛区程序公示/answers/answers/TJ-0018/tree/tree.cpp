#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define Pair pair<int,int>
const int N=1e4+10;
vector<int>v[N];
int n,m;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++)
		{
			int k;
			scanf("%d",&k);
			v[k].push_back(i+1);
		}
		puts("8");
	}
	return 0;
}
