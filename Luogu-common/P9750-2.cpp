#include <bits/stdc++.h>
using namespace std;
bool p;
void print(int x,int y)
{
	if(x%y==0) cout<<x/y;//情况2
	else //情况3
	{
		int gcd=__gcd(abs(x),abs(y));
		if(x>0&&y>0) cout<<x/gcd<<"/"<<y/gcd;
		else if(x<0&&y<0) cout<<-x/gcd<<"/"<<-y/gcd;
		else cout<<"-"<<abs(x)/gcd<<"/"<<abs(y)/gcd;
	}
}
void print1(int x,int y)
{
	if(!x) cout<<"0";//输出的情况1，由于这里只有整数，那么如果答案为0，还要输出
	else print(x,y);//普通情况
	cout<<"\n";//当前这个例子处理完毕，换行
}
void print2(int x,int y)
{
	if(!x) return ;//输出的情况1，由于这里后面还有根号，那么如果答案为0，不用输出
	else print(x,y);//同上
	cout<<"+";//后面要跟根号
}
void gen(int x,int y)
{
	int xishu=0;
	for(int i=1;i*i<=x;i++)
		if(x%(i*i)==0) xishu=i;//找平方数
	x=x/(xishu*xishu);
	y=abs(y);
	int gcd=__gcd(xishu,y);
	y/=gcd;
	xishu/=gcd;//约分
	
	
	if(xishu==1) cout<<"sqrt("<<x<<")";//如果系数为1，那么不用输出
	else cout<<xishu<<"*"<<"sqrt("<<x<<")";//这里要输出系数
	if(y!=1) cout<<"/"<<y;//分母的处理
	cout<<"\n";
}
void work()
{
	int a,b,c;
	cin>>a>>b>>c;
	b=-b;
	int t=2*a;
	int sq=b*b-4*a*c;
	if(t<0) p=1;
	else p=0;//这是对于较大根的处理
	
	if(sq<0) cout<<"NO\n";//情况1
	else if(sq==0) print1(b,t);//2
	else if((int)sqrt(sq)*(int)sqrt(sq)==sq) //3
	{
		int sum=(p==1?-sqrt(sq):sqrt(sq))+b;//考虑较大根
		print1(sum,t);//合并后输出
	}
	else//4
	{
		print2(b,t);//前面整数的输出
		gen(sq,t);//根号的输出
	}
}
int main()
{
	//int T,x;
	//cin>>T>>x;
	//T=1;x=1000;
	
	work();	
	
	return 0;
}
