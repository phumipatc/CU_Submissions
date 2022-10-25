#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
	//write your code here
	int idx = (mFront + pos)%mCap;
	T val = mData[idx];
	for(int i=pos;i<mSize;i++,idx++,idx%=mCap)
		mData[idx] = mData[(idx+1)%mCap];
	mData[(mFront + mSize - 1)%mCap] = val;
}

#endif
