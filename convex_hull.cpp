#include <iostream>
#include <vector>
#include <algorithm>
#include "convex_hull_header.cpp"
using namespace std;

int main(){
	int n;
	cout<<"Enter no. of points:(Minimum 3)"<<endl;
	cin>>n;
	vector<Point> p;
	vector<Point> CH; //convex hull;
	cout<<"Enter points:"<<endl;
	int i;
	Point a;
	for(i=0; i<n; i++){
		cin>>a.x;
		cin>>a.y;
		p.push_back(a);
	}
	CH = Convex_Hull(p,n);
	cout<<"Points:"<<endl;
	for(i=0; i<CH.size(); i++){
		cout<<CH[i].x<<" "<<CH[i].y<<endl;
	}

}
