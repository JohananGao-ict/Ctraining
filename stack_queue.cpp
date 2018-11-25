#include <iostream>
#include <stack>
#include <queue>
using namespace std;



int main(void){    
	
	stack<int> st;  //栈没有迭代器，不能随机访问
	
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	
	
	while(!st.empty()){
		cout<<st.top()<<' ';
		st.pop();
	}
	
	cout<<endl<<"----------------------------------"<<endl;
	
	queue<int> sq;  //队列没有迭代器，不能随机访问
	
	sq.push(100);
	sq.push(200);
	sq.push(300);
	sq.push(400);
	sq.push(500);
	while(!sq.empty()){
		cout<<sq.front()<<' ';
		sq.pop();
	}
	cout<<endl<<"----------------------------------"<<endl;
	
	
	
	return 0;
}

