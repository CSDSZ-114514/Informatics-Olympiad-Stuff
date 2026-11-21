#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
struct N{
	long long nn;
	long long vs;
};
int cnt = 0;
long long n,m;
long long a[100005][3];
N on[100005];
N tw[100005];
N smy[100005];
int cl[100005];
long long idd;
long long e;
long long gp[100005];
long long gps;
long long gpn;
bool qus = 0;

void swapp(int i){
	int temp;
	temp = a[i][1];
	a[i][1] = a[i][2];
	a[i][2] = temp;
}
int minu(){
	int mi = 0x3f3f3f3f;
	int id;
	for(int i = 1; i <= n; i++){
		if(a[i][1] < mi){
			mi = a[i][1];
			id = i;
		}
	}
	//cout << mi << "()" << endl;
	return id;
}

void al(){
	for(int j = 1; j <= n; j++){
		int mi1 = 0x3f3f3f3f;
		int mi2 = 0x3f3f3f3f;
		int mi3 = 0x3f3f3f3f;
		int id1,id2,id3;
		for(int i = 1; i <= n; i++){
			if(a[i][1] < mi1 && on[i].vs == 0){
				mi1 = a[i][1];
				id1 = i;
			}
			if(a[i][2] < mi2 && tw[i].vs == 0){
				mi2 = a[i][2];
				id2 = i;
			}
			if(a[i][0] < mi3 && smy[i].vs == 0){
				mi3 = a[i][0];
				id3 = i;
			}
		}
		on[id1].nn = j;
		on[id1].vs = 1;
		/*mi = 0x3f3f3f3f;
		for(int i = 1; i <= n; i++){
			
		}*/
		tw[id2].nn = j;
		tw[id2].vs = 1;
		/*mi = 0x3f3f3f3f;
		for(int i = 1; i <= n; i++){
			
		}*/
		smy[id3].nn = j;
		smy[id3].vs = 1;
	}
	for(int i = 1; i <= n; i++){
		cl[i] = on[i].nn + tw[i].nn + smy[i].nn;
		on[i].vs = 0;
		tw[i].vs = 0;
		smy[i].vs = 0;
	}
	
	int mi = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++){
		if(cl[i] < mi){
			mi = cl[i];
			idd = i;
		}
	}
	for(int i = 1; i <= n; i++){
		if(cl[i] == mi && i != idd){
			if(on[i].nn < on[idd].nn){
				mi = cl[i];
				idd = i;
				//cout << 23456789 << endl;
			}
		}
	}
	
	int mii = minu();
	if(m < a[mii][1] ){
		return;
	}
	/*while(a[mii][1] < a[idd][1]){
		if(m<0){
			break;
		}
		cout << m << " " << a[mii][1] << "_"<< endl;
		m -= a[mii][1];
		cnt++;
		swapp(mii);
		mii = minu();
	}*/
	for(int i = 1; i <= n; i++){
		if(a[i][1] < a[idd][1] || a[i][1] < a[idd][2]){
			gp[i] = a[i][1];
			//cout << a[i][1] << "(" << endl;
			gpn+=a[i][1];
			gps++;
		} 
	}
	//cout << gpn << " " << gps << "|"<< endl;
	if(gpn>a[idd][1] + a[idd][2]){
		qus = 1;
	//	cout << "te";
	}
}

void greedy(){
	int mii = minu();
	if(m < a[mii][1] ){
		return;
	}
	//al();
	
	//cout << id << "===" << endl;
	bool y = 0;
	if(qus && m <= gpn){
		y = 1;
	}
	if((m >= a[idd][1] + a[mii][1] || m >= a[idd][1] + a[idd][2]) && y == 0){
		//cout << m << " " << a[idd][1] << "---" << endl;
		/*if(qus && m - a[idd][1] <= gpn){
			m -= gpn;
			cnt += gps;
			cout << m << endl;
		} else {
			
		}*/
		m -= a[idd][1];
		cnt++;
		swapp(idd);
	} else if(m >= a[mii][1]){
		//cout << m << " " << a[mii][1] << "___"<< endl;
		m -= a[mii][1];
		cnt++;
		swapp(mii);
	}
	greedy();
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2];
		a[i][0] = a[i][1] + a[i][2];
	}
	/*al();
	for(int i = 1; i <= n; i++){
		cout << on[i].nn <<" "<< tw[i].nn << " " << smy[i].nn<<endl;
	}*/
	al();
	e = a[idd][1];
	greedy();
	cout << cnt << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
