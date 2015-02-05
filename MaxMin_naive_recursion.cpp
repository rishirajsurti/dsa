#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tuple_{
	int max, min;
	};
typedef Tuple_ Tuple;

Tuple MaxMin(vector<int> A, int low, int high);
int main(){
	cout<<"Enter n:"<<endl;
	int n;
	cin>>n;
	cout<<"Enter Array:" <<endl;
	vector<int> A;
	A.push_back(-999);
	int i,j;
	for(i=0; i<n; i++){
		cin>>j;
		A.push_back(j);
	}
	Tuple Result;
	Result = MaxMin(A,1,n);
	cout<<"Max: "<<Result.max<<" Min: "<<Result.min<<endl;
}

Tuple MaxMin(vector<int> A, int low, int high){
	Tuple r;
	if(high == low){
		r.max = A[low];
		r.min = A[low];
		return r;
	}
	else{
		int mid;
		mid = (low+high)/2;
		Tuple r1,r2;
		r1 = MaxMin(A, low, mid);
		r2 = MaxMin(A, mid+1, high);
		r.max = (r1.max > r2.max) ? r1.max : r2.max ;
		r.min = (r1.min < r2.min) ? r1.min : r2.min ;
		return r;
	}	
}
