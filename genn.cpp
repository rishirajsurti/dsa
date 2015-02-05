#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct Point_{
	int r,c;
};
typedef Point_ Point;
deque<Point> q;
int main(){
	Point p,d;
	p.r =1;
	p.c =2;
	q.push_back(p);
	d = q[0];
	cout<<d.c<<endl;

}