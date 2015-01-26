#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tuple_{
	int x,y,z;
	Tuple_(int a, int b, int c){
		x=a; y=b; z=c;
	}
};
typedef Tuple_ Tuple;

Tuple Max_Crossover_Sum(vector<int> a, int low, int mid, int high);
Tuple Max_Subarray(vector<int> a, int low, int high);


int main(){
	int n;
	cout<<"Enter size of array:"<<endl;
	cin>>n;
	vector<int> a;
	cout<<"Enter elements of array:"<<endl;
	int i,j;
	for(i=0; i<n; i++){
		cin>>j;
		a.push_back(j);
	}
	Tuple result(0,0,0);

	result = Max_Subarray(a,0,a.size()-1);
	cout<<result.x<<" to "<<result.y<<" Sum:"<<result.z<<endl;
	return 0;

}

Tuple Max_Subarray(vector<int> a, int low, int high){
	
	if(low==high){
		return Tuple(low,high,a[low]);
	}
	else{

	int mid = (low+high)/2;
	Tuple left(0,0,0);
	Tuple right(0,0,0);
	Tuple cross(0,0,0);
	left = Max_Subarray(a,low,mid);
	right = Max_Subarray(a,mid+1,high);
	cross = Max_Crossover_Sum(a, low,mid,high);

	if(left.z >= right.z && left.z >= cross.z)
		return left;
	else if (right.z >= left.z && right.z >=cross.z)
		return right;
	else return cross;

	}

}

Tuple Max_Crossover_Sum(vector<int> a, int low, int mid, int high){
	int i;
	int left_index, left_sum=-999999, sum=0;
	
	for(i=mid; i>=low; i--){
		sum = sum + a[i];
		if(sum > left_sum){
			left_sum = sum;
			left_index = i;
		}
	}
	//left_sum: max sum in left part of crossover array;
	//left_index: index of start of crossover array;

	int right_index, right_sum=-999999;
	sum=0; //initialize sum to 0;
	//high: max possible index of array
	for(i=mid+1; i<=high; i++){
		sum = sum + a[i];
		if(sum > right_sum){
			right_sum = sum;
			right_index = i;
		}
	}
	//right_sum: max sum in right part of crossover array;
	//right_index: index of termination of max crossover array;
	Tuple result(0,0,0);
	result.x = left_index;
	result.y = right_index;
	result.z = left_sum + right_sum;
	return result;
}
