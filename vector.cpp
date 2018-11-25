#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void ddd(int v){
	cout << v <<' ';
}


int main(){
	vector<int> v;
	
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	
	vector<int>::iterator pbin = v.begin();
	vector<int>::iterator pend = v.end();
	
	for_each(pbin, pend, ddd);
	
	return 0;
}
