#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 4
struct Point_{
	int r,c;
};
typedef Point_ Point;

stack<Point> State;
vector<Point> State_2;
stack<Point> Node;

void Backtrack(int n, stack<Point> State);
bool ValidPosition(stack<Point> State, Point Position);
bool SolutionFound = false;
int Mod(int a, int b);

int main(){
	Backtrack(4,State);
	cout<<"supp"<<endl;

	while(!State.empty()){
		cout<<State.top().r<<" "<<State.top().c<<endl;
		State.pop();
	}
}

void Backtrack(int n, stack<Point> State){
	
	if(n==0)
		SolutionFound = true;

	if(SolutionFound == true)
		return;

	int row,col;
	Point p;
	for(row=n; row>=1; row--)
	{
		for(col=1; col<=SIZE; col++)
		{
			p.r = row;	p.c = col;
			//cout<<"Row: "<<row<<" Col: "<<col<<endl;
			if( ValidPosition(State, p)){
				State.push(p);
				cout<<"Pushed: "<<State.top().r<<" "<<State.top().c<<" N:"<<n<<endl;				
				Backtrack(n-1, State);
				State.pop();
				//cout<<"After Pushed: "<<State.top().r<<" "<<State.top().c<<" N:"<<n<<endl;
			}
			else{
				if(col == SIZE){
					cout<<"Popping: "<<State.top().r<<" "<<State.top().c<<" N:"<<n<<endl;				
					//State.pop();
					return;
				}
			}
		}
	}	
}

int Mod(int a, int b){
	return (a>b ? (a-b):(b-a));
}

bool ValidPosition(stack<Point> State, Point Position)
{
	Point p;
	bool result;
	result = true;
	//cout<<"valid "<<result<<endl;
	stack<Point> State2;
	while(!State.empty()){
		p = State.top();
		State2.push(p);
		State.pop();
		if(p.r==Position.r || p.c==Position.c)
			result = false;
		else if(Mod(p.r,Position.r) == Mod(p.c,Position.c))
			result = false;
	}

	while(!State2.empty()){
		p = State2.top();
		State.push(p);
		State2.pop();
	}
//	cout<<"valid end "<<result<<endl;
	return result;
}
