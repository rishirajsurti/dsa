#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	string s;
	s = "rishi";
	do{
		cout<<s<<endl;
	}while(next_permutation(s.begin(),s.end()));
	return 0;
}