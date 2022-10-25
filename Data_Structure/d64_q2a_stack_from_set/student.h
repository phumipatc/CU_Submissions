#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
	//write your code ONLY here
	stack<T > temp;
	while(first != last)
		temp.push(*first),first++;
	mData = new T[temp.size()];
	mCap = temp.size();
	mSize = temp.size();
	for(int i = 0;i < mSize;i++)
		mData[i] = temp.top(),temp.pop();
}

#endif