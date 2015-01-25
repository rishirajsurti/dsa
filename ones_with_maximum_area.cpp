#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point_{
	int x,y;
};
typedef Point_ Point;

struct Rect_{
	Point p1,p2;
};
typedef Rect_ Rect;

void getMaxOnes(vector< vector<int> >);
int area=0;
Rect MaxOnes;

int main(){
	int n;
	cout<<"Enter no. of rows of a square matrix:"<<endl;
	cin>>n;
	cout<<"Enter the matrix:"<<endl;
	int i,j,k;

	vector< vector<int> > a;
	
	vector<int> row;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cin>>k;
			row.push_back(k);
		}
		a.push_back(row);
		row.clear();
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void getMaxOnes(vector< vector<int> > a){
	

}
