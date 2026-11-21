#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,m,ma,x[100008],a,b,xa,xi,jishu=0;
	float xy=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(xy==0 || xy>a+b || xy==a+b&&a<xa)
		{
			xy=a+b;
			xa=a;
			xi=i;
		}
		x[i]=a;
	}
	
	bool pd=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]<=xy/2)
		{
			ma+=x[i];
			jishu++;
			if(ma>m)
			{
				ma-=x[i];
				jishu--;
				pd=1;
				break;
			}
			else if(ma==m)
			{
				pd=1;
				break;
			}
		}
	}
	
	if(pd==1 || (m-ma)<xy/2) cout<<jishu<<endl;
	else
	{
		jishu+=(m-ma)/xy*2;
		int z=(m-ma)/xy*2;
		ma+=z*xy;
		if(ma+x[xi]<=m) jishu++;
		cout<<jishu<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
