#include <iostream>
#include "segments_intersect_header.cpp"
using namespace std;
int main(){
	cout<<"P1P2 and P3P4"<<endl;
	cout<<"Enter x y in order P1-P2-P3-P4"<<endl;
	Vector p1,p2,p3,p4;
	cin>>p1.x>>p1.y;
	cin>>p2.x>>p2.y;
	cin>>p3.x>>p3.y;
	cin>>p4.x>>p4.y;
	if(Segments_Intersect(p1,p2,p3,p4))
		cout<<"Intersect"<<endl;
	else
		cout<<"Do not intersect"<<endl;
}