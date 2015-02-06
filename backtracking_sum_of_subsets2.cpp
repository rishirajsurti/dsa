#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
bool Subset(vector<int> A , int i, int Sum);
void Print(deque<int> Index);
deque<int> Index;
int main(){
	cout<<"enter size: "<<endl;
	int n;
	cin>>n;
	cout<<"Enter Array: "<<endl;
	int i,j;
	vector<int> A;
	for(i=0; i<n; i++){
		cin>>j;
		A.push_back(j);
	}
	cout<<"Enter Sum: "<<endl;
	int RSum; //Required sum;
	cin>> RSum;

	if(Subset(A,0,RSum))
		cout<<"Hurray"<<endl;
	else
		cout<<"Not Found!"<<endl;
}
	
bool Subset(vector<int> A , int i, int Sum){
	
	if(Sum == 0)
		return true;
	if(Sum < 0 || i >= A.size()){
		Index.pop_back();
		return false;
	}
	if(Subset(A,i+1,Sum-A[i]) == true){
		Index.push_back(i);
		return true;
	}
	else
		if(Subset(A,i+1, Sum) == true)
			return true;
		else{
			return false;
		}
}
void Print(deque<int> Index){
	int i;
	if(!Index.empty()){
	cout<<"( ";	
	for(i=0; i<Index.size(); i++){
		cout<<Index[i]<<",";
	}
	cout<<endl;
}
}