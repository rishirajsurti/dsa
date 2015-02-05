#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Find_Pivot(vector<int> a);
vector<int> ArraySort(vector<int> a);

vector<int> QuickSort(vector<int> A, int Pivot_Value);

int main(){
	int n;
	cout<<"Enter array size:"<<endl;
	cin>>n;
	int m;
	m = (n/5);
	//to check for m: use mod 4.. coz a[0] is first element.
	cout<<"Enter array elements:"<<endl;
	vector<int> Array;
	vector< vector<int> > Pivot_Array;
	vector<int> row;
	vector<int> Median_Array;
	int i,j,k;
	for(i=0; i<n; i++){
		cin>>k;
		Array.push_back(k);

		row.push_back(k);
		if((i+1)%5 == 0){

			Pivot_Array.push_back(ArraySort(row));
			Median_Array.push_back( Pivot_Array.back()[2] );
			row.clear();
		}
	}

//	for(i=0; i<Median_Array.size(); i++)
//		cout<<Median_Array[i]<<endl;
/*	for(i=0; i<Pivot_Array.size(); i++){
		for(int j=0; j<Pivot_Array[i].size(); j++){
			cout<<Pivot_Array[i][j]<<" ";
		}
		cout<<endl;
	}*/
//		cout<<Array[i]<<endl;
	//array : ready;
	//2d array of n/5 rows: ready with each row sorted;
	//Median array: ready;
	//For Pivot: Sort Median array and find the median;
	int Pivot;

	Pivot = Find_Pivot(Median_Array);
	cout<<"Pivot: "<<Pivot<<endl;
	vector<int> Sorted_Array;
	Sorted_Array = QuickSort(Array, Pivot);
}

vector<int> ArraySort(vector<int> a){
	//just a 5 element array;
	//use bubble sort;
	int i,j,k,max;
	for(i=0; i<a.size(); i++){
		for(j = a.size()-1; j>=i+1; j--){
			if(a[j]<a[j-1]){
				k = a[j];
				a[j] = a[j-1];
				a[j-1]=k;
			}
		}
	}
	return a;
}
int Find_Pivot(vector<int> a){
	//use bubble sort;
	int i,j,k,max;
	for(i=0; i<a.size(); i++){
		for(j = a.size()-1; j>=i+1; j--){
			if(a[j]<a[j-1]){
				k = a[j];
				a[j] = a[j-1];
				a[j-1]=k;
			}
		}
	}
//	for(i=0; i<a.size(); i++)
//		cout<<a[i]<<endl;
	int Mid;
	Mid = (a.size()/2);

	return a[Mid];
}

vector<int> QuickSort(vector<int> A, int Pivot_Value){

}
