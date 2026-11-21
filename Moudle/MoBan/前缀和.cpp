#include<bits/stdc++.h>
using namespace std;
int s[10005][10005];

double SUM(int x1,int x2,int y1,int y2){
	return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}

int main(){
	
	
}
