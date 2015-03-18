#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int t[]={1,2,3,4};
	int i;
	do{
		for(i=0; i<4; i++)
			cout<<t[i]<<" ";
		cout<<endl;
	}while(next_permutation(t,t+4));
	return 0;
}