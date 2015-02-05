#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void MaxMin(vector<int> A, int low, int high, int *Max, int *Min);

int *Max_overall, *Min_overall;
int main(){
	int n;
	cout<<"Enter Size:"<<endl;
	cin>>n;
	vector<int> A;
	A.push_back(-999); //let array index start from 1 to n;
	int i=0,j;
	cout<<"Enter the array:"<<endl;
	while(++i<=n){
		cin>>j;
		A.push_back(j);
	}
	i=0;
	while(++i<=n){
		cout<<A[i]<<endl;
	}
	Max_overall = (int *)malloc(sizeof(int));
	Min_overall = (int *)malloc(sizeof(int));
	MaxMin(A,1,n,Max_overall,Min_overall);
	cout<<*Max_overall<<" "<<*Min_overall<<endl;
}

void MaxMin(vector<int> A, int low, int high, int *Max, int *Min){
	Max = (int *)malloc(sizeof(int));
	Min = (int *)malloc(sizeof(int));
	if(low == high){
		*Max = A[low];
		*Min = A[low];
		
	}
	else{
		int *Max1, *Min1; //left subtree;
		int *Max2, *Min2; //right subtree;
		int mid;
		mid = (low+high)/2;
		Max1 = (int *)malloc(sizeof(int));
		Min1 = (int *)malloc(sizeof(int));
		Max2 = (int *)malloc(sizeof(int));
		Min2 = (int *)malloc(sizeof(int));
		
		MaxMin(A, low, mid, Max1, Min1);
		MaxMin(A, mid+1, high, Max2, Min2);
		
		*Max = (*Max1 > *Max2 ? *Max1 : *Max2);
		*Min = (*Min1 < *Min2 ? *Min1 : *Min2);
		cout<<"Max: "<<*Max1<<" Min: "<<*Min1<<endl;
		}
//	cout<<"Max: "<<*Max1<<" Min: "<<*Min1<<endl;
	return;	
}