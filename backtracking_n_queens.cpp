#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
/*
n queens
stack in form of tuple x,y;
x is the queen number : the row in which it is placed
y is the coloumn number;
*/
struct Point_{
	int r,c;	//r=row, c=col;
};
typedef Point_ Point;

stack<Point> State;
stack<Point> Node;

void Backtrack(int n, stack<Point> State);
// n : number of queens;
// state: current state of the board;

bool Check(stack<Point> State, Point  Next_Queen);
//check the conditions on the state;
//true if valid state; false if not;

int main(){
	Backtrack(4,State);
	while(!State.empty()){
		cout<<State.top().r<<" "<<State.top().c<<endl;
		State.pop();
	}
}

void Backtrack(int n, stack<Point> State){
	int row,col;
	Point p;
	for(row=n; row>=1; row--){ 	// n=4;
		for(col=1; col<=n; col++){	//1 to 4;
			p.r = row; //4
			p.c = col;	//1

			if(Check(State, p)){ // true if p can be placed, false if not
				State.push(p);
				Backtrack(n-1, State);			
			}
			else{// the point is not valid
				//check if all the cols are checked
				if(col == n){
					State.pop();
					Backtrack(n+1,State);
				}
				else
					continue; //continue with the next iteration;
			}
		}
	}
}
bool Check(stack<Point> State, Point Next_Queen){
	Point p;
	bool result;
	stack<Point> State2;
	while(!State.empty()){
		p = State.top();
		State2.push(p);
		State.pop();
		if(p.r == Next_Queen.r || p.c==Next_Queen.c)
			result = false;
		else if( (Next_Queen.r-p.r)/(Next_Queen.c-p.c)==1 || (Next_Queen.r-p.r)/(Next_Queen.c-p.c)==-1 )
			result = false;
		else
			result = true;
	}
	while(!State2.empty()){
		p = State2.top();
		State.push(p);
		State2.pop();
	}
	return result;
}