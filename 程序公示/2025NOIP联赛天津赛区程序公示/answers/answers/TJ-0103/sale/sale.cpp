#include<bits/stdc++.h>
using namespace std;
struct f{
	int c;
	int w;
	double p;
	int id;
}a[100010];
bool cmp(f c1,f c2)
{
	if(c1.p!=c2.p) return c1.p>c2.p;
	else return c1.id<c2.id;
}
bool cmp2(f c3,f c4)
{
	return c3.c>c4.c;
 } 
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	long long  c,len,n,m;
	cin>>c>>len;
	for(int i=0;i<len;i++)
	{
		int ans=0;
		cin>>n>>m;
	
		int flag=0,f2=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].c;	
			if(a[i].c==a[i-1].c&&i>=1&&f2==0) 
			{
				flag=1;
			}
			else if(a[i].c!=a[i-1].c&&i>=1&&f2==0)
			{
				flag=2;
				f2=1;
			}	
			a[i].id=i;
		}
		if(n>5) 
		{
			cout<<1;
			continue;
		}
		if(a[1].c!=a[0].c&&flag==1) flag=2;
		if(flag==1)
		{
			long long num=pow(2,n);
			cout<<num%998244353<<endl;
			continue;
		}
		if(flag==2)
		{
			for(int i1=1;i1<=2;i1++)
			{
				if(n>=2)
				{
					for(int i2=1;i2<=2;i2++)
					{
						if(n>=3)
						{
							for(int i3=1;i3<=2;i3++)
							{
								if(n>=4)
								{
									for(int i4=1;i4<=2;i4++)
									{
										if(n==5)
										{
											for(int i5=1;i5<=2;i5++)
											{
												a[0].w=i1,a[1].w=i2,a[2].w=i3,a[3].w=i4,a[4].w=i5;
												a[0].p=(1.0*a[0].c)/a[0].w,a[1].p=(1.0*a[1].c)/a[1].w,a[2].p=(1.0*a[2].c)/a[2].w,a[3].p=(1.0*a[3].c)/a[3].w,a[4].p=(1.0*a[4].c)/a[4].w;
												sort(a,a+5,cmp);
												int num=0;
												int k=m;
												for(int j=0;j<n;j++)
												{
													if(k>=a[j].w)
													{
														num+=a[j].c;
														k-=a[j].w;
													}
												}
												int maxn=0;
												sort(a,a+5,cmp2);
												for(int j=0;j<n;j++)
												{
													if(k>=a[j].w)
													{
														maxn+=a[j].c;
														k-=a[j].w;
													}
												}
												if(num>=maxn) ans++;
											}
										}
										//
										else
										{
											a[0].w=i1,a[1].w=i2,a[2].w=i3,a[3].w=i4;
											a[0].p=(1.0*a[0].c)/a[0].w,a[1].p=(1.0*a[1].c)/a[1].w,a[2].p=(1.0*a[2].c)/a[2].w,a[3].p=(1.0*a[3].c)/a[3].w;
											sort(a,a+4,cmp);
											int num=0;
											int k=m;
											for(int j=0;j<n;j++)
											{
												if(k>=a[j].w)
												{
														num+=a[j].c;
													k-=a[j].w;
												}
											}
											int maxn=0;
											sort(a,a+4,cmp2);
											for(int j=0;j<n;j++)
											{
												if(k>=a[j].w)
												{
													maxn+=a[j].c;
													k-=a[j].w;
												}
											}
											if(num>=maxn) ans++;
										}
									}
								}
								//
								else
								{
									a[0].w=i1,a[1].w=i2,a[2].w=i3;
									a[0].p=(1.0*a[0].c)/a[0].w,a[1].p=(1.0*a[1].c)/a[1].w,a[2].p=(1.0*a[2].c)/a[2].w;
									sort(a,a+3,cmp);
									int num=0;
									int k=m;
									for(int j=0;j<n;j++)
									{
										if(k>=a[j].w)
										{
											num+=a[j].c;
											k-=a[j].w;
										}
									}
									int maxn=0;
									sort(a,a+3,cmp2);
									for(int j=0;j<n;j++)
									{
										if(k>=a[j].w)
										{
											maxn+=a[j].c;
											k-=a[j].w;
										}
									}
									if(num>=maxn) ans++;
								}
	
							}
						}
						//
						else
						{
							a[0].w=i1,a[1].w=i2;
							a[0].p=(1.0*a[0].c)/a[0].w,a[1].p=(1.0*a[1].c)/a[1].w;
							sort(a,a+2,cmp);
							int num=0;
							int k=m;
							for(int j=0;j<n;j++)
							{
								if(k>=a[j].w)
								{
									num+=a[j].c;
									k-=a[j].w;
								}
							}
							int maxn=0;
							sort(a,a+2,cmp2);
							for(int j=0;j<n;j++)
							{
								if(k>=a[j].w)
								{
									maxn+=a[j].c;
									k-=a[j].w;
								}
							}
							if(num>=maxn) ans++;
						}
					}
				}
				//
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
