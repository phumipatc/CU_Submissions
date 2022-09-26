#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
	//your code here
	stack<T > temp,temp2;
	while(m-- && !s2.empty())
		temp.push(s2.top()),s2.pop();
	while(k-- && !empty())
		temp2.push(top()),pop();
	while(!temp.empty())
		push(temp.top()),temp.pop();
	while(!temp2.empty())
		push(temp2.top()),temp2.pop();
}
#endif
