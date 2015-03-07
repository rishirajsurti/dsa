#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
void SubStrings(string s,int a, int b);
int main(){
	string s;
	s = "rishiraj";
//	SubStrings(s,0,s.length()-1);
	cout<<s.substr(0,s.length());
}

void SubStrings(string s,int a, int b){
	int i,j;
	for(i=a; i<=b; i++){
		for(j=i; j<=b; j++)
			cout<<s.substr(i,j)<<endl;
	}
}