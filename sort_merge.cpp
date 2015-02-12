#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> MergeArrays(vector<int> A1, vector<int> A2);
vector<int> MergeSort(vector<int> A, int low, int high);

int main(){
	int n;	
	vector<int> A;
	int i,j;
	cout<<"Enter size:"<<endl;
	cin>>n;
	cout<<"Enter array:"<<endl;
	for(i=0; i<n; i++){
		cin>>j;
		A.push_back(j);
	}
	A = MergeSort(A,0,n-1);
	for(i=0; i<A.size(); i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

vector<int> MergeSort(vector<int> A, int low, int high){
	if(low==high){
		vector<int> M;
		M.push_back(A[low]);
		return M;
	}
	else{
		int mid;
		mid = (low+high)/2;
		vector<int> Left, Right, Merged;
		Left = MergeSort(A,low, mid);
		Right = MergeSort(A, mid+1, high);
		Merged = MergeArrays(Left,Right);
//		int j;
	//	for(j=0; j<Merged.size(); j++)
	//		cout<<Merged[j]<<" ";
	//	cout<<endl;
		return Merged;
	}
}

vector<int> MergeArrays(vector<int> A1, vector<int> A2){
	vector<int> A;
	int i,j;
	i=0;	j=0;
	while(i<A1.size() && j<A2.size()){
		if(A1[i] > A2[j]){
			A.push_back(A2[j]);
			j++;
		}
		else{
			A.push_back(A1[i]);
			i++;
		}
	}
	while(i<A1.size()){
		A.push_back(A1[i]);
		i++;
	}
	while(j<A2.size()){
		A.push_back(A2[j]);
		j++;
	}
	return A;
}