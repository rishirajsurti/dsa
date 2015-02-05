#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 4
struct Point_{
	int r,c;
};
typedef Point_ Point;	

deque<Point> State;
deque<Point> Node;

bool ValidPosition(deque<Point> State, Point Position);
int Mod(int a, int b);
void Backtrack(int n, deque<Point> State);

bool SolutionFound = false;

int main(){
	Backtrack(4,State);
}

void Backtrack(int n, deque<Point> State){
	if(n==0)
		SolutionFound = true;

	if(SolutionFound == true)
		return;

	int row, col;
	Point p;
	p.r = n;

	for(col = 1; col <= SIZE; col++){

		p.c = col;
			if(ValidPosition(State, p)){
				State.push_back(p);
				Backtrack(n-1, State);
			}
			else{
				if(col == SIZE){
					State.pop_back();
					Backtrack(n+1, State);
				}
			}
	}

	
}

int Mod(int a, int b){
	return (a>b ? (a-b):(b-a));
}

bool ValidPosition(deque<Point> State, Point Position)
{
	Point p;
	bool result;
	result = true;
	int i;
	for(i=0; i<State.size(); i++){
		p = State[i];
		if(p.r==Position.r || p.c==Position.c)
			result = false;
		else if(Mod(p.r,Position.r) == Mod(p.c,Position.c))
			result = false;
	}
	return result;
}
