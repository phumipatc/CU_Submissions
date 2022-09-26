#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<algorithm>

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
	//write your code here
	// if you use std::vector, your score will be half (grader will report score BEFORE halving)
	for(int i=0;i<std::min(size(),other.size());i++){
		if(mData[i] == other[i])	continue;
		return mData[i] < other[i];
	}
	return size() < other.size();
}

#endif
