#include<iostream>
#include<algorithm>
using namespace std;
struct student{
	string name;
	int Chinese;
	int Math;
	int English;
	int Sum;
} ;
student a[1005];
bool cmp1(student x,student y){
	if(x.Sum!=y.Sum){
		return x.Sum>y.Sum;
	}else if(x.Chinese!=y.Chinese){
		return x.Chinese>y.Chinese;
	}
	else if(x.Math!=y.Math){
		return x.Math>y.Math;
	}else{
		return x.name<y.name;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].name>>a[i].Chinese>>a[i].Math>>a[i].English;
		a[i].Sum = a[i].Chinese+a[i].Math+a[i].English; 
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++){
		cout<<a[i].name<<" "<<a[i].Chinese<<" "<<a[i].Math<<" "<<a[i].English<<" "<<endl;
	}
	return 0;
}
