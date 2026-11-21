#include<bits/stdc++.h>
using namespace std;
long long n,m;
bool flag1=1,flag2=1;
struct node{
	long long x,y,m;
};
bool cmp(node a,node b)
{
	return a.x<b.x;
}
bool cmp2(node a,node b)
{
	return a.m<b.m;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	
	node a[n]={},b[n]={}; 
	long long ans1=0,ans2=0,m2=m,m3=m,minna=1e9,xiabiao,lol,m6=m;
	
	for(long long i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].y;
		
		b[i].x=a[i].x;
		b[i].y=a[i].y;//第二数组 
		b[i].m=b[i].x+b[i].y;
		
		a[i].m=a[i].x+a[i].y;//总 
		if(minna>a[i].m)
		{
			minna=a[i].m;
			xiabiao=a[i].x;
			lol=i;//位置 
		}
		//minna=min(minna,a[i].m);
		
		if(a[i].x==a[i].y)
		{
			ans1=max(ans1,m/a[i].x);//特判 
			m=m6;
		}
	}
	sort(a,a+n,cmp); //取最小x 

	for(long long i=0;i<n;i++)
	{
		if(a[i].x<minna&&m>=a[i].x&&m>=0)
		{
			ans2++;
			m-=a[i].x;//小于minna的和 
		}
	}
	//cout<<m<<endl;
	//sort(b,b+n,cmp2);
	long long sum=0;
	bool flag=1;
	m2=m;
	for(long long i=0;i<n;i++)
	{
		if(sum>m2)
		{
			ans2-=1;
			flag=0;
			break;
		}
		if(a[i].x<minna)
		{
			sum+=a[i].x;
		}else{
			//flag2=0;
			break;
		}
	}
	//if(flag==0)
	//{
		//cout<<max(ans1,ans2);
	//	return 0;
	//}
	m2=m;
	for(long long i=0;i<=1e9;i++)
	{
		if(m2>=b[lol].y&&i%2==0)
		{
			ans2++;
			m2-=b[lol].y;
		}
		else {
			//cout<<ans2;
			break;
		}
		if(m2>=b[lol].x&&i%2==1)
		{
			ans2++;
			m2-=b[lol].y;
		}
		else { 
			break;
		}
	}
	long long ans3=(m3/minna)*2;
	cout<<max(ans3,max(ans1,ans2));
	
	//cout<<endl<<ans1<<' '<<ans2<<' '<<ans3<<' ';
	//cout<<minna;
	
	return 0;
 } 
