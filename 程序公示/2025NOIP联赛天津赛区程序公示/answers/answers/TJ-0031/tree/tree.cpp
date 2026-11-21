#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int a[8010],l1[8010],l2[8010];

bool cmp(int x,int y)
{
    return x > y;
}


int main()
{
    freopen("tree.in","r",stdin);freopen("tree.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(l1,0,sizeof(l1));
        int n,m;
        int ans = 0,l1n = 0;
        scanf("%d %d",&n,&m);
        for(int i = 2 ; i <= n ; i++)
        {
            int pa;
            scanf("%d",&pa);
            if(pa != 1) l1[pa]++;
            else l1n++;
        }
        sort(l1+1,l1+n+1,cmp);
        ans += l1[1]+2;
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(l1[i] == 0) break;
            ans += l1[i]+2;
            cnt++;
        }
        ans += l1n-cnt;
        printf("%d\n",ans);
    }
    return 0;
}
