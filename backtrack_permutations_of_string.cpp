#include <iostream>
#include <string>
using namespace std;
void SubStrings(string s,int i);
//i starting index;
int main(){
	string s;
	s= "abc";
//	cout<<s<<endl;
	SubStrings(s,0);
}

void SubStrings(string s,int i){
	int j;
	char c;
	if(i==s.length())
		cout<<s<<endl;
	else{
		for(j=i; j<s.length(); j++){
			c = s[i];
			s[i] = s[j];
			s[j] = c;
			SubStrings(s,i+1);
			c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}
}