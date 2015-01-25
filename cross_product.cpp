#include <iostream>
using namespace std;

struct Vector_{
	int x,y;
};
typedef Vector_ Vector;

Vector Vector_Sub(Vector v1, Vector v2);
int Vector_Cross(Vector v1, Vector v2);

int main(){
	Vector p0,p1,p2;
	cout<< "(P1-P0)x(P2-P0)"<<endl;
	cout<<"Enter P0: "<<endl;
	cin>>p0.x;
	cin>>p0.y;
	
	cout<<"Enter P1: "<<endl;
	cin>>p1.x;
	cin>>p1.y;

	cout<<"Enter P2: "<<endl;
	cin>>p2.x;
	cin>>p2.y;

	cout<< Vector_Cross(Vector_Sub(p1,p0),Vector_Sub(p2,p0))<<endl;
}
Vector Vector_Sub(Vector v1, Vector v2){
	Vector v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return v;
}

int Vector_Cross(Vector v1, Vector v2){
	return (v1.x*v2.y - v1.y*v2.x);
}