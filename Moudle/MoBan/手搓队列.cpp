#include <bits/stdc++.h>
using namespace std;
class queue_class{
private:
	int queue_class_array[1000005],queue_class_front=1,queue_class_back=1,queue_class_size=0;
	const int queue_class_full_size=100000;
public:
	bool qcempty();
	bool qcfull();
	void qcpush(int num);
};
bool queue_class::qcempty(){
	if(queue_class_back!=queue_class_front){
		return true;
	}else{
		return false;
	}
}
bool queue_class::qcfull(){
	if(!qcempty()){
		if(queue_class_back>queue_class_front){
			
		}
		if(queue_class_back<queue_class_front){
			
		}
	}
	else{
		return false;
	}
}
