#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
#include <stack>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
	//WRITE YOUR CODE HERE
	//DON"T FORGET TO RETURN THE RESULT
	stack<int > st;
	for(auto x:v){
		if(x.first == 1)
			st.push(x.second);
		else{
			int num2 = st.top();
			st.pop();
			int num1 = st.top();
			st.pop();
			if(x.second == 0)
				st.push(num1 + num2);
			else if(x.second == 1)
				st.push(num1 - num2);
			else if(x.second == 2)
				st.push(num1 * num2);
			else
				st.push(num1 / num2);
		}
	}
	return st.top();
}

#endif
