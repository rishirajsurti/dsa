#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
struct Point{
	int x,y;
};

int main(){
	vector<Point> a;
	Point p;
	p.x=2;
	p.y=3;
	a.push_back(p);
	cout<<sizeof(a)<<" "<<sizeof(Point)<<" "<<a.size()<<endl;
}