#include <iostream>
#include <list>
#include <iterator>


using namespace std;

void print_list(list<int>& T){
	for(list<int>::iterator it=T.begin(); it!=T.end(); it++){
		cout<<*it<<' ';
	}
	cout<<endl;
}

bool mycompare(int v1,int v2){
	return v1>v2;
}

int main(){   //链表
	list<int> lis;
	lis.push_back(0);
	lis.push_back(-4);
	lis.push_back(4);
	lis.push_back(2);
	lis.push_back(10);
	
	print_list(lis);
	//默认排序从小到大
	lis.sort();  //默认排序从小到大
	//lis.sort(mycompare);  //默认排序从大到小
	
	
	print_list(lis);
	lis.reverse();
	print_list(lis);
	
	return 0;
}


