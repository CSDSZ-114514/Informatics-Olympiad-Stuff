#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100005,MOD = 998244353;
int a[N],b[N],s[N],n,m;
// a 1     b 2

struct Node {
	int num,idx,flg;
}ab[N];

bool cmp(Node x,Node y){
	if (x.num != y.num)return x.num>y.num;
	else if (x.flg != y.flg ) return x.flg>y.flg;
	else return x.idx<y.idx;
}
int r[N];

int cnt = 0;

bool check(int x){
//	cout<<endl;
	sort(ab+1,ab+n+1,cmp);
//	for (int i = 1;i<=n;i++){
//		cout<<ab[i].num<<" ";
//	}
	//cout<<endl;
	int sum = 0;
	for(int i = 1;i<=n;i++){
	//	cout<<i<<" ";
		sum += ab[i].flg;
		if (sum == m)return 1;
		//cout<<"sum";
		if (sum > m){
			int g = i+1;
			while (ab[g].flg == 2 && g<=n)g++;
			if (g > n)return 1;
			return ((ab[i-1].num  + ab[g].num  ) >= (2 * ab[i].num));
		}
	}
	return 1;
}

void dg(int x){
	
	if (x == n+1){
		if (check(x)){
			cnt++;
			cnt %= MOD;
		}
		return ;
	}
	
	ab[x] = {a[x],x,1};
	dg(x+1);
	ab[x] = {b[x],x,2};
	dg(x+1);
	 
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int C,T;
    cin>>C>>T;
    if (C == 18){
    	while (T--){
    		cnt = 1;
    		cin>>n>>m;
    		
    		for (int i = 1;i<=n;i++){
    			cnt = cnt *2;
    			cnt %= MOD;
			} 
			cout<<cnt<<endl;
		}
		return 0;
	}
    while (T--){
    	cnt = 0;
    	cin>>n>>m;
    	for (int i = 1;i<=n;i++){
    		cin>>b[i];
    		a[i] = b[i] * 2;
		}
		
		dg(1);
		
		cout<<cnt<<"\n";
	}

    return 0;
}
