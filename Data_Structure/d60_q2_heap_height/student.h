#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include <math.h>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
	//write your code here
	if(mSize == 0)	return -1;
	return floor(log2(mSize));
}

#endif

