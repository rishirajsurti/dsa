#include <iostream>
#include <vector>
using namespace std;

vector<int> InsertionSort(vector<int>);

int main(){
	int n;
	cout<<"Enter No. of Elements:"<<endl;
	cin>>n;
	int i,j;
	vector<int> a;
	for(i=0; i<n; i++){
		cin>>j;
		a.push_back(j);
	}
	a=InsertionSort(a);
	for (i=0;i<n;i++)
		cout<<a[i]<<" ";

}

vector<int> InsertionSort(vector<int> a){
	int size = a.size();
	int i,j,k;
	int key;

	for (i=1; i<size; i++){
	
		key = a[i];
		j=i-1;
		while(a[j]>key && j>=0){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
		/*
		for (k=0;k<size;k++)
			cout<<a[k]<<" ";
		cout<<endl;*/
	}
	return a;
}