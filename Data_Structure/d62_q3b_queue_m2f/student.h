#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    //your code here
	T val = mData[(mFront + pos)%mCap];
	for(int i = pos,idx = (mFront + pos)%mCap;i>0;i--,idx = (idx - 1 + mCap)%mCap){
		mData[idx] = mData[(idx - 1 + mCap)%mCap];
	}
	mData[mFront] = val;
}

#endif
