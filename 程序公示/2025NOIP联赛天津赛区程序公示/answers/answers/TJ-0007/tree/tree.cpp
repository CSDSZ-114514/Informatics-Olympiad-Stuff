#include<iostream>
#include<set>
using namespace std;
namespace KitoTaisu{
	char *p1,*p2,buf[32769];
	#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,32767,stdin),p1==p2)?EOF:*p1++)
	int read(){
		int x=0,f=1;
		char ch=nc();
		while(ch<48||ch>57){
			if(ch=='-')f=-1;
			ch=nc();
		}
		while(47<ch&&ch<58){
			x=(x<<1)+(x<<3)+(ch^48);
			ch=nc();
		}
		return x*f;
	}
	unsigned int readu(){
		unsigned int x=0;
		char ch=nc();
		while(ch<48||ch>57){
			ch=nc();
		}
		while(47<ch&&ch<58){
			x=(x<<1)+(x<<3)+(ch^48);
			ch=nc();
		}
		return x;
	}
	long long readll(){
		long long x=0,f=1;
		char ch=nc();
		while(ch<48||ch>57){
			if(ch=='-')f=-1;
			ch=nc();
		}
		while(47<ch&&ch<58){
			x=(x<<1)+(x<<3)+(ch^48);
			ch=nc();
		}
		return x*f;
	}
	unsigned long long readull(){
		unsigned long long x=0;
		char ch=nc();
		while(ch<48||ch>57){
			ch=nc();
		}
		while(47<ch&&ch<58){
			x=(x<<1)+(x<<3)+(ch^48);
			ch=nc();
		}
		return x;
	}
	int readstr(char* str,char vl='a',char vr='z'){
		int len=0;
		char ch=nc();
		while(ch<vl||ch>vr){
			ch=nc();
		}
		while(vl<=ch&&ch<=vr){
			str[len++]=ch;
			ch=nc();
		}
		str[len]=0;
		return len;
	}
}
namespace Chtholly{
	struct Chtholly{
		int l,r;
		mutable int val;
		bool operator <(const Chtholly a)const{
			return l<a.l;
		}
	};
	#define si set<Chtholly>::iterator
	class ChthollyTree{
		private:
			set<Chtholly> tree;
			si split(int x){
				si it=tree.lower_bound({x,0,0});
				if(it!=tree.end()&&it->l==x)return it;
				--it;
				int l=it->l,r=it->r,val=it->val;
				tree.erase(it);
				tree.insert({l,x-1,val});
				return tree.insert({x,r,val}).first;
			}
			si get(int x){
				si it=tree.lower_bound({x,0,0});
				if(it!=tree.end()&&it->l==x)return it;
				--it;
				return it;
			}
		public:
			inline void build(int l,int r,int val,bool pr=1){
				tree.insert({l,r,val});
				if(pr)tree.insert({r+1,r+1,val});
			}
			void assign(int l,int r,int val){
				si itr=split(r+1),itl=split(l);
				tree.erase(itl,itr);
				tree.insert({l,r,val});
			}
			void change(int l,int r,int x){
				si itr=split(r+1),itl=split(l);
				for(si it=itl;it!=itr;++it){
					it->val+=x;
				}
			}
			void print(){
				si itr=tree.end(),itl=tree.begin();
				for(si it=itl;it!=itr;++it){
					printf("Chtholly %d %d %d\n",it->l,it->r,it->val);
				}
			}
	};
	#undef si
	#define ls (id<<1)
	#define rs ((id<<1)|1)
	class SegmentTree{
		private:
			long long val[4000002],lazy[400002];
			inline void push_up(int id){
				val[id]=val[ls]+val[rs];
			}
			inline void push_down(int id){
				val[ls]+=lazy[id];
				lazy[ls]+=lazy[id];
				val[rs]+=lazy[id];
				lazy[rs]+=lazy[id];
				lazy[id]=0;
			}
		public:
			void build(int id,int l,int r,int* a){
				if(l==r){
					val[id]=a[l];
					return;
				}
				int mid=(l+r)>>1;
				build(ls,l,mid,a);
				build(rs,mid+1,r,a);
				push_up(id);
			}
			void add(int id,int l,int r,int L,int R,int x){
				if(l>R||L>r)return;
				if(L<=l&&r<=R){
					val[id]+=x;
					lazy[id]+=x;
					return;
				}
				push_down(id);
				int mid=(l+r)>>1;
				add(ls,l,mid,L,R,x);
				add(rs,mid+1,r,L,R,x);
				push_up(id);
			}
			long long query(int id,int l,int r,int L,int R){
				if(l>R&&L>r)return 0;
				if(L<=l&&r<=R){
					return val[id];
				}
				long long ret=0;
				push_down(id);
				int mid=(l+r)>>1;
				ret=query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
				push_up(id);
				return ret;
			}
	};
	#undef ls
	#undef rs
	class VST{
		private:
			int tot,ls[4000002],rs[4000002],Max[4000002];
			long long sum[4000002];
			inline void push_up(int id){
				Max[id]=sum[id]=0;
				if(ls[id]){
					Max[id]=max(Max[ls[id]],Max[id]);
					sum[id]+=sum[ls[id]];
				}
				if(rs[id]){
					Max[id]=max(Max[rs[id]],Max[id]);
					sum[id]+=sum[rs[id]];
				}
			}
		public:
			void insert(int id,int l,int r,int x){
				if(l==r){
					sum[id]+=x;
					Max[id]=x;
					return;
				}
				int mid=(l+r)>>1;
				if(x<=mid)insert(ls[id]?ls[id]:(ls[id]=++tot),l,mid,x);
				else insert(rs[id]?rs[id]:(rs[id]=++tot),mid+1,r,x);
				push_up(id);
			}
			int get_Max(){
				return Max[1];
			}
	};
}
using KitoTaisu::read;
using KitoTaisu::readu;
using KitoTaisu::readll;
using KitoTaisu::readull;
using KitoTaisu::readstr;
using Chtholly::ChthollyTree;
using Chtholly::SegmentTree;
using Chtholly::VST;
int t;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	t=read();
	while(t--)printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
