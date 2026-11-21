#include<bits/stdc++.h>
using namespace std;
string c,k;string m;
int main(){
	cin>>k>>c;
	for(int i=0;i<k.length();i++){
		if(k[i]>'Z'){
			k[i]=k[i]-'a'+'A';
		}
	}
	//cout<<k<<endl;
	int w=k.length();
	for(int i=0;i<c.length();i++){
		int b=i%w;
		//cout<<b;
		m=new char;
		m[i]=c[i]- k[b]+'A';
		if(c[i]>='a'&&m[i]<'a'){
			m[i]+=26;
		}else if(c[i]>='A'&&c[i]<='Z'&&m[i]<'A'){
			m[i]+=26;
		}
		
	}
	printf_s("%s",&m);
}
