#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


struct Point_{
	int x,y;
};
typedef Point_ Point;

vector<Point> Convex_Hull(vector<Point>, int );
int CrossProduct(Point v1, Point v2);
Point Vector_Subtract(Point v1, Point v2);


vector<Point> Convex_Hull(vector<Point> P_, int n){
	stack<Point> p; //to store points;
	int i;
	for(i=n-1; i>=0; i--)
		p.push(P_[i]);
	//now p is a stack of points top to bottom;
//	cout<<p.top().x<<endl;
	stack<Point> s1;
	stack<Point> s2; //dummy stack;
	s1.push(p.top());
	p.pop();
	s1.push(p.top());
	p.pop();
	s2.push(p.top());
	p.pop();
			
	while(!p.empty()){
		// as per CLRS:
		// s1.top()= p1
		// s2.top()= p2
		//	p.top()= p3;
		//find turn angle p3p2p1;
		//s2 will be pushed no matter what
		// p.pop();
		// cross product of p2-p3 and p2-p1 should be negative for non-left turn;
		// cross product of s2.top()-p.top() and s2.top()-s1.top() should be negative for non-left turn;
		if( CrossProduct( Vector_Subtract( s2.top(),p.top() ), Vector_Subtract(s2.top(), s1.top())) < 0){ //Point part of convex hull
			s1.push(s2.top()); //p2
			s1.push(p.top());	//p3
			s2.pop();	
			p.pop();	//p3 removed
			
			s2.push(s1.top()); // access element below top;
			s1.pop();
			//s2.push(p.top());
			
		}
		else{ //takes a left turn; s2 is not part of convex hull;
			p.pop();
		}
	//	cout<<"Point: "<<s1.top().x<<" "<<s1.top().y<<endl;

	}
	s1.push(s2.top());
	s2.pop();
	//cout<<s1.size()<<endl;
	vector<Point> CH;
	while(!s1.empty()){
		CH.push_back(s1.top());
		s1.pop();
	}

	return CH;
}


Point Vector_Subtract(Point v1, Point v2){
	Point v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return v;
}
int CrossProduct(Point v1, Point v2){
	//
	return (v1.x*v2.y - v1.y*v2.x);
}