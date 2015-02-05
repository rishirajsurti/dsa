#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

bool SumOfSubsets(int index, int Sum);
vector<int> A;
int main(){
	cout<<"Enter Array size"<<endl;
	int n;
	cin>>n;
	cout<<"Enter Array:"<<endl;
	int i,j;
	for(i=0; i<n; i++){
		cin>>j;
		A.push_back(j);
	}
	cout<<"Enter the sum:"<<endl;
	int M;
	cin>>M;
	if(SumOfSubsets(0,M)){
		cout<<"hurray"<<endl;
	}
}

bool SumOfSubsets(int index, int Sum){
	cout<<index<<" "<<Sum<<endl;

	if(Sum==0 && index<=A.size())
		return true;
	if(index>A.size() || Sum<0)
		return false;
	if(SumOfSubsets(index+1,Sum))
		return true;
	if(SumOfSubsets(index+1,Sum-A[index])){
		cout<<index<<" "<<Sum<<endl;
		return true;
	}
//	return false;
}
