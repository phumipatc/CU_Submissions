#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::valid_iterator(CP::vector<T>::iterator it) const {
	//write your code here
	auto it1 = &mData[0];
	auto it2 = &mData[mSize-1];
	return (it >= it1 && it <= it2);
}

#endif
