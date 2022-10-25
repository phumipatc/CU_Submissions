#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>
#include <algorithm>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
	//write your code here
	while(idx > 0){
		int p = (idx-1)/4;
		if(mLess(mData[idx],mData[p]))	break;
		std::swap(mData[idx],mData[p]);
		idx = p;
	}
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
	while(idx < mSize){
		int c = 4*idx+1;
		int target = idx;
		while(c <= 4*idx+4 && c < mSize){
			if(mLess(mData[target],mData[c]))	target = c;
			c++;
		}
		if(target == idx)	break;
		std::swap(mData[idx],mData[target]);
		idx = target;
	}
}

#endif

