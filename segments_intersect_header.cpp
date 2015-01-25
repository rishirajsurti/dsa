#include <iostream>

using namespace std;
struct Vector_{
	int x,y;
};
typedef Vector_ Vector;

int CrossProduct(Vector v1, Vector v2);
Vector Vector_Subtract(Vector v1, Vector v2);
bool Segments_Intersect( Vector p1, Vector p2, Vector p3, Vector p4);
bool On_Segment(Vector p1, Vector p2, Vector p3);

Vector Vector_Subtract(Vector v1, Vector v2){
	Vector v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return v;
}
int CrossProduct(Vector v1, Vector v2){
	return (v1.x*v2.y - v1.y*v2.x);
}


bool Segments_Intersect( Vector p1, Vector p2, Vector p3, Vector p4){
	int d1,d2,d3,d4;
	d1 = CrossProduct(Vector_Subtract(p3,p1),Vector_Subtract(p4,p1));
	d2 = CrossProduct(Vector_Subtract(p2,p3),Vector_Subtract(p2,p4));
	d3 = CrossProduct(Vector_Subtract(p3,p1),Vector_Subtract(p3,p2));
	d4 = CrossProduct(Vector_Subtract(p4,p1),Vector_Subtract(p4,p2));

	if( ((d1>0 && d2<0) || (d1<0 && d2>0)) &&
		((d3>0 && d4<0) || (d3<0 && d4>0)) ){
		return true;
	}
	else if (d1==0 && On_Segment(p3,p4,p1))
		return true;
	else if (d2==0 && On_Segment(p3,p4,p2))
		return true;
	else if (d3==0 && On_Segment(p1,p2,p3))
		return true;
	else if (d4==0 && On_Segment(p1,p2,p4))
		return true;
	else
		return false;
}
bool On_Segment(Vector p1, Vector p2, Vector p3){
	if(	(p1.x>p2.x ? p2.x : p1.x)<=p3.x && p3.x<=(p1.x>p2.x ? p1.x : p2.x) &&
		(p1.y>p2.y ? p2.y : p1.y)<=p3.y && p3.y<=(p1.y>p2.y ? p1.y : p2.y) )
		return true;
	else
		return false;
}