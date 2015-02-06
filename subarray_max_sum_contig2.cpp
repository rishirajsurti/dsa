#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Tuple_{
	int l,r,sum;
};
typedef Tuple_ Tuple;
Tuple MaxCrossoverArray(vector<int> A, int low, int high);
Tuple MaxSubarray(vector<int> A, int low, int high);
int main(){
	cout<<"Enter size: "<<endl;
	int n;
	cin>>n;
	cout<<"Enter array:"<<endl;
	vector<int> A;
	A.push_back(-999);
	int i,j;
	for(i=0; i<n; i++){
		cin>>j;
		A.push_back(j);
	}
	Tuple MaxSumResult;
	MaxSumResult = MaxSubarray(A, 1, n);
	cout<<MaxSumResult.l<<" "<<MaxSumResult.r<<" "<<MaxSumResult.sum<<endl;
}

Tuple MaxSubarray(vector<int> A, int low, int high){
	Tuple left_result, right_result, cross_result;
	int mid = (low+high)/2;
	left_result = MaxCrossoverArray(A, low , mid);
	right_result = MaxCrossoverArray(A, mid+1, high);
	cross_result = MaxCrossoverArray(A, low , high);

	if(left_result.sum > right_result.sum){
		if(cross_result.sum > left_result.sum)
			return cross_result;
		else
			return left_result;
	}
	else{
		if(cross_result.sum > right_result.sum)
			return cross_result;
		else
			return right_result;

	}
}

Tuple MaxCrossoverArray(vector<int> A, int low, int high){
	int left_sum = 0;
	int mid = (low+high)/2;
	int left_index;
	int sum =0, i;
	for(i = mid; i >= low; i--){
		sum+=A[i];
		if(sum > left_sum){
			left_sum = sum;
			left_index = i;
		}
	}

	int right_sum = 0;
	int right_index;
	sum =0;
	for(i = mid+1; i<= high; i++){
		sum += A[i];
		if(sum > right_sum){
			right_sum = sum;
			right_index = i;
		}
	}
	Tuple result;
	result.l = left_index;
	result.r = right_index;
	result.sum = (left_sum + right_sum);
	return result;
}