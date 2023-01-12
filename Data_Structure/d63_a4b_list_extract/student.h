#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
	//write your code here
	while(a != b){
		if((*a) != value){
			a++;
			continue;
		}
		node *now = a.ptr;
		a++;
		now->prev->next = now->next;
		now->next->prev = now->prev;
		now->prev = output.mHeader;
		now->next = output.mHeader->next;
		output.mHeader->next->prev = now;
		output.mHeader->next = now;
		output.mSize++;
		mSize--;
	}
}

#endif
