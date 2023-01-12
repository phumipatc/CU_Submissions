#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
	//write your code here
	if(a == b)	return a;
	auto ret = a;
	b--;
	while(a != b){
		std::swap(*a,*b);
		if(++a == b)	break;
		b--;
	}
	return ret;
}

#endif
