#include<bits/stdc++.h>
using namespace std;
long long s[10005];
long long s1[10005],s2[10005];
long long n,m;
//struct sp{
	//int s1,s2;
//};
int dp(long long mn,long long h){
	int i,j = 0,ans = h;
	for(i = 0;i < n;i++){
		if(mn - s[i] < 0){
			j += 1;
			continue;
		}
		int mn1 = mn - s[i];
		s[i] = s2[i];
		s2[i] = s1[i];
		s1[i] = s[i];
		ans = max(ans,dp(mn1,h + 1));
	}
	return ans;
	if(j == n){
		return h;
	}
}
int main(){
	//int min1 = 1000000000;
	long long min2 = 2000000009;
	long long i1,mm,ans = 0;
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> s1[i] >> s2[i];
		s[i] = s1[i];
		long long j = s1[i]+s2[i];
		
		if(min2 > j)
		{
			min2 = j;
			i1 = i;
			mm = min(s1[i],s2[i]);	
		}
		else if(min2 == j){
			long long mm1 = min(s1[i],s2[i]);
			if(mm1 < mm){
				i1 = i;
				mm = mm1;
			}
		}
		
		//min2 = min(min2,j1);
		//min1 = min(min1,s1[i]);
 	}
 	if(m < 20){
 		cout << dp(m,0);
	}
	else{
		long long mmm =m;
		//s1[i1] = max(s1[i1],s2[i1]); 
		for(int i = 0;i < n;i++){
			if(i == i1){
				if(s[i] == mm){
					m -= s[i];
					ans += 1;
					s[i] = s2[i];
					s2[i] = s1[i];
					s1[i] = s[i];
				}
			}
			if(s[i] <= mm){
				//cout << s[i] <<endl;
				m -= s[i];
				ans += 1;
				s[i] = s2[i];
				s2[i] = s1[i];
				s1[i] = s[i];
			}
		}
		//int minb = min2 *2;
		//cout << m << endl;
		long long lans1 = m / min2 - 1;
		//cout << lans1 << endl;
		ans += lans1 * 2;
		m -= lans1 * min2;
		//int distpp[m + 1];
		sort(s,s+n);
		long long la = 0;
		//cout << m << ' ' << ans << endl;
		long long l = 0;
		for(int i = 0;;i++){
			if((m - s[i])< 0){
				break;
			}
			else{
				//cout << s[i] << endl;
				l += s[i];
				m -= s[i];
				la += 1;
			}
		}
		if(la <= 2 && l >= min2){
			///cout << 111;
			m += l;
			m -= s1[i1];
			ans += 1;
			for(int i = 0;;i++){
				if((m - s[i])< 0){
					break;
				}
				else{
					//cout << s[i] << endl;
					//l += s[i];
					m -= s[i];
					ans += 1;
				}
			}	
		}
		else{
			ans += la;
		}
		if(m >= s2[i1]){
			m -= s2[i1];
			ans += 1;
			if(m >= s1[i1]){
				ans += 1; 
			}
		}
		//cout << mm << endl; 
		///int lll = mmm/min2;
		cout <<  ans;
	}
} 
