#include <iostream>
#include <deque>
#include <vector>
using namespace std;

#define N 16
struct Point_{
	int r,c;
};
typedef Point_ Point;

deque<Point> State;
bool ValidPosition(deque<Point>, Point Position);
int Mod(int a, int b);
bool Backtrack(int col, deque<Point> State);
void PrintState(deque<Point> State);

int main(){
	Backtrack(0,State);
	return 0;
}

bool Backtrack(int row, deque<Point> State){
	if(row>=N){
		PrintState(State);
		return true;
	}
	int col;
	Point p;
	p.r = row;
	for(col = 0; col<N; col++){
		p.c = col;
		if(ValidPosition(State,p)){
			State.push_back(p);
			if(Backtrack(row+1, State)==true)
				return true;
			else{
				State.pop_back();
			}
		}
	}
	return false;

}

void PrintState(deque<Point> State){
	cout<<State.size()<<endl;
	int i,j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(State[i].c==j)
				cout<<" @ " ;
			else
				cout<<" - ";
		}
		cout<<endl;
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

