#include <iostream>
using namespace std;

struct Vector_{
	int x,y;
};
typedef Vector_ Vector;

int CrossProduct(Vector v1, Vector v2);
Vector Vector_Subtract(Vector v1, Vector v2);

Vector Vector_Subtract(Vector v1, Vector v2){
	Vector v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return v;
}
int CrossProduct(Vector v1, Vector v2){
	//
	return (v1.x*v2.y - v1.y*v2.x);
}
