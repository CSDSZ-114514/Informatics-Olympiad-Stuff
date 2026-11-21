#include<bits/stdc++.h>
using namespace std;
struct node{
	bool typ;
	long long dat;
	bool friend operator <(node thi,node oth)
	{
		if(thi.dat==oth.dat) return (!thi.typ && oth.typ);//avg first
		return thi.dat<oth.dat;
	}
	bool friend operator >(node thi,node oth)
	{
		if(thi.dat==oth.dat) return (thi.typ && !oth.typ);
		return thi.dat>oth.dat;
	}
} cand[300003];
long long a,b;
long long p1[100001],p2[100001];
void solveA()
{
	long long lowp=INT_MAX;
	for(long long I=0;I<a;I++) lowp=min(lowp,p1[I]);
	b/=2;
	cout<<b/lowp;
}
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	b*=2;
	for(long long I=0;I<a;I++) cin>>p1[I]>>p2[I];
	bool spA=true;
	for(long long I=0;I<a;I++)
		if(p1[I]!=p2[I])
		{
			spA=false;
			break;
		}
	if(spA)
	{
		solveA();
		return 0;
	}
	long long ans=0,c=0;
	for(long long I=0;I<a;I++)
	{
		p1[I]*=2,p2[I]*=2;
		cand[c].dat=p1[I],cand[c].typ=true;
		c++;
		cand[c].dat=(p1[I]+p2[I])/2,cand[c].typ=false;
		c++;
	}
	sort(cand,cand+c);
	long long i=0;
	while(b>=cand[i].dat)
	{
		if(cand[i].typ)
		{
			ans+=1;
			b-=cand[i].dat;
			i++;
		}
		else
		{
			long long took_pair=b/(2*cand[i].dat);
			ans+=took_pair*2;
			b-=b/(2*cand[i].dat)*2*cand[i].dat;
			i++;
		}
		if(i>=c) break;
	}
	cout<<ans;
	
	return 0;
}
