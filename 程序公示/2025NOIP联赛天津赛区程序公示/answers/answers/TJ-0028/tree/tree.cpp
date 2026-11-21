#include <bits/stdc++.h>
using namespace std;
int t,n,m;
int fa[8005];
vector<int> g[8005];
int depth[8005];
int cnt1=0,cnt2=0;

void dfs(int cur)
{
    for(auto i:g[cur])
    {
        if(i!=fa[cur])
        {
            depth[i]=depth[cur]+1;
            dfs(i);
        }
    }

    if(g[cur].size()==1)
    {
        cnt2++;
    }
    else cnt1++;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cnt1=cnt2=0;
        memset(depth,0,sizeof(depth));
        memset(g,0,sizeof(g));
        int n,m;
        cin>>n>>m;
        // cout<<n<<" "<<m<<endl;
        for(int i=2;i<=n;i++)
        {
            cin>>fa[i];
            g[fa[i]].push_back(i);
        }
        dfs(1);
        cout<<cnt2+cnt1*2+1<<endl;
    }
}
    