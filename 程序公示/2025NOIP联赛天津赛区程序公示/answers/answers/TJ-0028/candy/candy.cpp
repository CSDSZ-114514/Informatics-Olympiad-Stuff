#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
pair<int,int> a[N];
int sum[N];
int n,m;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}
signed main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
        sum[i]=a[i].first+a[i].second;
    }
    sort(sum+1,sum+n+1);
    sort(a+1,a+n+1,cmp);
    int v=sum[1],pos=0;
    int s=0;
    // cerr<<v<<endl;
    int min_second=LLONG_MAX;
    for(int i=1;i<=n-1;i+=2)
    {
        // cerr<<a[i].first<<" "<<a[i+1].first<<endl;
        if(a[i].first+a[i+1].first>v)
        {
            break;
        }
        pos=i+1;
    }
    for(int i=1;i<=pos;i++) s+=a[i].first;
    

    int res=(m-s)/v*2+pos;
    int rem=(m-s)/v;
    rem*=v;
    rem+=s;
    // cerr<<a[pos+1].first<<endl;
    
    if(pos!=n && m-rem>=a[pos+1].first)
    {
        res++;
    }
    else if(m-(rem-a[pos].first)>=v)
    {
        res++;
    }
    cout<<res<<endl;

}
/*
This is my last competition in OI.
I started learning it from Junior One.
And I will AFO on 2025/11/29, no matter how good or bad I've done.
I will graduate from senior high soon.

I used to be a contestant in Jiangsu Province.
I am a graduate from Nanjing Foreign Language School.
After being admitted by the Young Gifted Program of Xi'an Jiaotong University, I went to Tianjin Nankai High School for my first year's course.
Life here is very interesting. I met many kind people, who offered me support.
After NOIP 2025, I will be an XCPCer instead of an OIer.
With regrets and grief.

I love OI.
I love computer science.
I think I will be a computer programmer in the future.

I have made a lot of friends with OI.
zzk2010(My junior high school classmate, currently studying in Middle School Affiliated to Nanjing Normal University), piggy123(Also my junior high school classmate,who studies in Nanjing Foreign Language School now) are my best friends in junior high.
I wish you RP++.
I hope you can enter the provincial team of Jinagsu Province.
And... I miss the joy and happiness in Nanjing Foreign Language School.
I miss my friends.

I hope that we can all be someone great one day.

NOIP 2023 JS-0269
NOIP 2025 TJ-0028

Different provinces, but similar determination.

OI

from 2022/7/6 to 2025/11/29

Farewell.

XSS_Worm (luogu uid 704330)

Junior High    2022-2025       Nanjing Foreign Language School
Senior High    2025-2026       Tianjin Nankai High School
University     2025-2031       Xi'an Jiaotong University
*/
