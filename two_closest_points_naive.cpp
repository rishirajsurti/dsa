#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point_{
	int x,y;
};
typedef Point_ Point;

int Distance(Point, Point);

int main(){
	int n,i,j;
	int min_d=10000000, min_e;
	Point p;
	vector<Point> a;
	cout<<"Enter number of points:"<<endl;
	cin>>n;
	for (i=0; i<n; i++){
		
		cin>>p.x;
		cin>>p.y;
		a.push_back(p);
	}

	for(i=0; i<n; i++)
		cout<<a[i].x<<" "<<a[i].y<<endl;	

	vector< vector<int> > d;
	vector<int> row;
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			row.push_back(Distance(a[i],a[j]));
		}
		d.push_back(row);
		min_e = *min_element(row.begin(),row.end());
		min_d = min_e > min_d ? min_d : min_e;

		row.clear();
	}
	cout<<min_d<<endl;
}
int Distance(Point m, Point n){
	return ((m.x-n.x)*(m.x-n.x)+(m.y-n.y)*(m.y-n.y));
}