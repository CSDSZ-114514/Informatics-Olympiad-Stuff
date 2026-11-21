#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
const long long mod=1e9+7;
long long a[N],sum[N],g[N],kds[N];
vector<long long> fsum[N];
vector<long long> gsum[N];
long long qpow(long long a, long long b) {
	long long ans = 1;
	while(b) {
		if(b%2==1) { 
			ans = ans * a%mod;
		}
		b/=2;
		a = a*a%mod; 
	}
	return ans;
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<long long>());

    sum[0]=0;
    for(int i=1;i<=n;i++){//qzh
        sum[i]=(sum[i-1]+a[i])%mod;
    }

    long long tmp=0;
    for (int i = 1; i <= n; ++i) {
        tmp = qpow(i,mod-2);
        kds[i]=(tmp*tmp)%mod;
    }
    long long mxn=0;
    for(int i=1;i<=n;i++){//dp
        mxn=n/i;
        fsum[i].resize(mxn+1);
        gsum[i].resize(mxn+1);
        fsum[i][0]=0;
        gsum[i][0]=0;
        

        for(int j=1;j<=mxn;j++){
            long long sum1=(sum[i*j]-sum[i*(j-1)]+mod)%mod;
            long long beauty =(sum1*sum1)%mod*kds[i]%mod;//It's the beauty of mathematic.by zrc.
            fsum[i][j]=(fsum[i][j-1]+beauty)%mod;
        }

        for(int j=1;j<=mxn;j++){
            long long sum2=(sum[n-(j-1)*i]-sum[n-j*i]+mod)%mod;
            long long beauty =(sum2*sum2)%mod*kds[i]%mod;//It's the beauty of mathematic.by zrc.
            gsum[i][j]=(gsum[i][j-1]+beauty)%mod;
        }
    }
    long long l,r;
    long long exn,cnt1,cnt2,cnt3,tmp2;
    while(q--){
        long long ans=0;
        cin>>l>>r;
        if(l>n){cout<<-1<<'\n';continue;}
        mxn=n/l;
        exn=n-mxn*l;
        if(l==r){
            if(exn!=0)cout<<-1<<'\n';
            else cout<<fsum[l][mxn]<<'\n';
            continue;
        }
        cnt1=exn/(r-l);
        if(cnt1>0)ans=(ans+gsum[r][cnt1])%mod;
        tmp2=exn%(r-l);
        cnt2=0;
        if(tmp2>0)cnt2=1;
        else cnt2=0;
        cnt3=mxn-cnt1-cnt2;
        if(cnt3<0){cout<<-1<<'\n';continue;}
        if(cnt3>0)ans=(ans+fsum[l][cnt3])%mod;
        if(cnt2>0) { 
            long long ssum=(sum[cnt3*l+l+tmp2]-sum[cnt3*l]+mod)%mod;
            long long beauty=(ssum*ssum)%mod*qpow((long long)l+tmp2*l+tmp2%mod,mod-2)%mod;

            ans = (ans+beauty)%mod;
        }
        cout <<ans<<'\n';
    }
    return 0;
}