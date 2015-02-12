#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
#define N 4
struct Point_{
	int r,c; //row col
};
typedef Point_ Point;

bool ValidPosition(int g[N+1][N+1], Point Position, int value);

int main(){
	cout<<N<<"x"<<N<<" grid."<<endl<<"Enter known elements: "<<endl;
	cout<<"ROW COL VAL"<<endl;
	cout<<"E.g. 3 2 9"<<endl;
	cout<<"ALL VALUES IN RANGE 1-9"<<endl;
	cout<<"Enter -1 when done"<<endl;
	int grid[N+1][N+1]={0};
	int i,j;
	Point p;
	int v;
	cin>>p.r;
	while(p.r != -1){
		cin>>p.c;
		cin>>v;
		grid[p.r][p.c] = v;
		cin>>p.r;
	}	
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

bool ValidPosition(int g[N+1][N+1], Point Position, int value){
	bool result = true;
	int i,j;
	i = Position.r;
	for(j = 1; j <= N; j++){
		if(j!= Position.c){
			if(g[i][j] == value)
				result = false;
		}
	}

	j = Position.c;
	for(i = 1; i <= N; i++){
		if(i != Position.r){
			if( grid[i][j] == value )
				result = false;
		}
	}

	//won't check diagonal
	int m1,m2;
	m1 =( Position.r % 3 );	
	m2 =( Position.c % 3 );
	
}