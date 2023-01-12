#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::shift_left() {
	// your code here
	std::swap(mHeader->data,mHeader->next->data);
	mHeader = mHeader->next;
}

#endif
