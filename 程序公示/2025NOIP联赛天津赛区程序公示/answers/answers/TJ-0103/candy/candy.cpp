#include<bits/stdc++.h>
using namespace std;
struct f{
	int c1;
	int c2;
}a[100100];
int flag=0;
bool cmp1(f p1,f p2)
{
	return p1.c1<p2.c2;
}
bool cmp2(f p3,f p4)
{
	return (p3.c1+p3.c2)<(p4.c1+p4.c2);
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,m,ans=0,f2=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].c1>>a[i].c2;
		if(a[i].c1==a[i].c2&&f2==0) flag=1;
		else
		{
			flag=2;
			f2=1;	
		}
	}
	if(flag==1)
	{
		sort(a,a+n,cmp1);	
		for(int i=0;;i++)
		{
			if(m>=a[0].c1)
			{
				ans++;
				m-=a[0].c1;
			}
			else break;
		}
		cout<<ans;
	}
	else if(flag==2)
	{
		sort(a,a+n,cmp2);	
		for(int i=0;;i++)
		{
			if(i%2==0&&m>=a[0].c1)
			{
				m-=a[0].c1;
				ans++;
			}
			else if(i%2==1&&m>=a[0].c2)
			{
				
				m-=a[0].c2;
				ans++; 
			}
			else break;
		}
		cout<<ans;
	}
	//晋太元中，武陵人捕鱼为业，缘溪行，忘路之远近，忽逢桃花林。夹岸数百步，中无杂树。 
	//芳草鲜美，落英缤纷，渔人甚异之，复前行欲穷其林，林尽水源，便得一山。山有小口，
	//仿佛若有光，便舍船。从口入，初极狭，才通人，复行数十步豁然开朗，土地平旷，屋舍俨然。
	//有良田美池桑竹之属，阡陌交通鸡犬相闻，男女衣着悉如外人，黄发垂髫并怡然自乐。
	//见渔人，乃大惊，村中闻有此人，闲来问询，自云先世避秦时乱，率旗子邑人来此绝境。
	//不复出焉，遂与外人间隔，问今是何世，乃不知有汉，无论魏晋，渔人一一为具言所闻。
	//后面忘了，好几年没默过了，我要上大赏。 
	return 0;
}
